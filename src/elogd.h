/********************************************************************
 Name:         elogd.h
 Created by:   Stefan Ritt

 Contents:     Header file for ELOG program

 $Id: elogd.c 2354 2011-01-10 11:53:11Z ritt $

\********************************************************************/

/* Version of ELOG */
#define VERSION "2.8.1"

#define _GNU_SOURCE
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>
#include <locale.h>

/* Default name of the configuration file. */
#ifndef CFGFILE
#define CFGFILE "elogd.cfg"
#endif

/* Default TCP port for server. */
#ifndef DEFAULT_PORT
#define DEFAULT_PORT 80
#endif

#ifdef _MSC_VER

#define OS_WINNT

#define DIR_SEPARATOR '\\'
#define DIR_SEPARATOR_STR "\\"

#define snprintf _snprintf

#include <windows.h>
#include <io.h>
#include <conio.h>
#include <time.h>
#include <direct.h>
#include <sys/stat.h>

#else

#define OS_UNIX

#ifdef __APPLE__
#define OS_MACOSX
#endif

#define TRUE 1
#define FALSE 0

#ifndef O_TEXT
#define O_TEXT 0
#define O_BINARY 0
#endif

#define DIR_SEPARATOR '/'
#define DIR_SEPARATOR_STR "/"

#ifndef DEFAULT_USER
#define DEFAULT_USER "nobody"
#endif

#ifndef DEFAULT_GROUP
#define DEFAULT_GROUP "nogroup"
#endif

#ifndef PIDFILE
#define PIDFILE "/var/run/elogd.pid"
#endif

typedef int BOOL;

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <pwd.h>
#include <grp.h>
#include <syslog.h>
#include <termios.h>

#define closesocket(s) close(s)

#ifndef stricmp
#define stricmp(s1, s2) strcasecmp(s1, s2)
#endif

gid_t orig_gid;                 /* Original effective GID before dropping privilege */
uid_t orig_uid;                 /* Original effective UID before dropping privilege */
char pidfile[256];              /* Pidfile name                                     */

#endif                          /* OS_UNIX */

#ifdef __CYGWIN__               /* bug in cygwin, 'tmezone' not linked automatically */
long _timezone;
#endif

/* SSL includes */
#ifdef HAVE_SSL
#include <openssl/ssl.h>
#endif

/* local includes */
#include "regex.h"
#include "mxml.h"
#include "strlcpy.h"

#define SYSLOG_PRIORITY LOG_NOTICE      /* Default priority for syslog facility */

#define TELL(fh) lseek(fh, 0, SEEK_CUR)

#ifdef OS_WINNT
#define TRUNCATE(fh) chsize(fh, TELL(fh))
#else
#define TRUNCATE(fh) ftruncate(fh, TELL(fh))
#endif

#define NAME_LENGTH  1500

#define DEFAULT_TIME_FORMAT "%c"
#define DEFAULT_DATE_FORMAT "%x"

#define DEFAULT_HTTP_CHARSET "ISO-8859-1"

#define SUCCESS        1
#define FAILURE        0

#define EL_SUCCESS     1
#define EL_FIRST_MSG   2
#define EL_LAST_MSG    3
#define EL_NO_MSG      4
#define EL_FILE_ERROR  5
#define EL_UPGRADE     6
#define EL_EMPTY       7
#define EL_MEM_ERROR   8
#define EL_DUPLICATE   9
#define EL_INVAL_FILE 10

#define EL_FIRST       1
#define EL_LAST        2
#define EL_NEXT        3
#define EL_PREV        4

#define MAX_GROUPS       32
#define MAX_PARAM       120
#define MAX_ATTACHMENTS  50
#define MAX_N_LIST      100
#define MAX_N_ATTR      100
#define MAX_N_EMAIL     500
#define MAX_REPLY_TO    100
#define CMD_SIZE      10000
#define TEXT_SIZE    250000
#define MAX_PATH_LENGTH 256

#define MAX_CONTENT_LENGTH 10*1024*1024

/* attribute flags */
#define AF_REQUIRED           (1<<0)
#define AF_LOCKED             (1<<1)
#define AF_MULTI              (1<<2)
#define AF_FIXED_EDIT         (1<<3)
#define AF_FIXED_REPLY        (1<<4)
#define AF_ICON               (1<<5)
#define AF_RADIO              (1<<6)
#define AF_EXTENDABLE         (1<<7)
#define AF_DATE               (1<<8)
#define AF_DATETIME           (1<<9)
#define AF_TIME              (1<<10)
#define AF_NUMERIC           (1<<11)
#define AF_USERLIST          (1<<12)
#define AF_MUSERLIST         (1<<13)
#define AF_USEREMAIL         (1<<14)
#define AF_MUSEREMAIL        (1<<15)

/* attribute format flags */
#define AFF_SAME_LINE              1
#define AFF_MULTI_LINE             2
#define AFF_DATE                   4
#define AFF_EXTENDABLE             8

typedef struct {
   int message_id;
   char file_name[32];
   time_t file_time;
   int offset;
   int in_reply_to;
   unsigned char md5_digest[16];
} EL_INDEX;

typedef struct {
   char name[256];
   char name_enc[256];
   char data_dir[256];
   char top_group[256];
   EL_INDEX *el_index;
   int *n_el_index;
   int n_attr;
   PMXML_NODE pwd_xml_tree;
} LOGBOOK;

typedef struct {
   int message_id;
   unsigned char md5_digest[16];
} MD5_INDEX;

typedef struct LBNODE *LBLIST;

struct LBNODE {
   char name[256];
   LBLIST *member;
   int n_members;
   int is_top;
} LBNODE;

typedef struct {
   LOGBOOK *lbs;
   int index;
   char string[256];
   int number;
   int in_reply_to;
} MSG_LIST;

typedef struct {
   char user_name[256];
   char session_id[32];
   char host_ip[32];
   time_t time;
} SESSION_ID;

void show_error(char *error);
int is_verbose(void);
extern void eprintf(const char *, ...);
BOOL enum_user_line(LOGBOOK * lbs, int n, char *user, int size);
int get_user_line(LOGBOOK * lbs, char *user, char *password, char *full_name, char *email,
                  BOOL email_notify[1000], time_t * last_access, int *inactive);
int get_full_name(LOGBOOK *lbs, char *uname, char *full_name);
int set_user_inactive(LOGBOOK * lbs, char *user, int inactive);
int strbreak(char *str, char list[][NAME_LENGTH], int size, char *brk, BOOL ignore_quotes);
int execute_shell(LOGBOOK * lbs, int message_id, char attrib[MAX_N_ATTR][NAME_LENGTH],
                  char att_file[MAX_ATTACHMENTS][256], char *sh_cmd);
BOOL isparam(char *param);
char *getparam(char *param);
void write_logfile(LOGBOOK * lbs, const char *str);
BOOL check_login_user(LOGBOOK * lbs, char *user);
LBLIST get_logbook_hierarchy(void);
BOOL is_logbook_in_group(LBLIST pgrp, char *logbook);
BOOL is_admin_user(char *logbook, char *user);
BOOL is_admin_user_global(char *user);
void free_logbook_hierarchy(LBLIST root);
void show_top_text(LOGBOOK * lbs);
void show_bottom_text(LOGBOOK * lbs);
int set_attributes(LOGBOOK * lbs, char attributes[][NAME_LENGTH], int n);
void show_elog_list(LOGBOOK * lbs, int past_n, int last_n, int page_n, BOOL default_page, char *info);
int change_config_line(LOGBOOK * lbs, char *option, char *old_value, char *new_value);
int read_password(char *pwd, int size);
int getcfg(char *group, char *param, char *value, int vsize);
int build_subst_list(LOGBOOK * lbs, char list[][NAME_LENGTH], char value[][NAME_LENGTH],
                     char attrib[][NAME_LENGTH], BOOL format_date);
void highlight_searchtext(regex_t * re_buf, char *src, char *dst, BOOL hidden);
int parse_config_file(char *config_file);
PMXML_NODE load_password_file(LOGBOOK * lbs, char *error, int error_size);
int load_password_files();
void compose_base_url(LOGBOOK * lbs, char *base_url, int size, BOOL email_notify);
void show_elog_entry(LOGBOOK * lbs, char *dec_path, char *command);
char *loc(char *orig);
void strencode(char *text);
void strencode_nouml(char *text);
int scan_attributes(char *logbook);
int is_inline_attachment(char *encoding, int message_id, char *text, int i, char *att);
int setgroup(char *str);
int setuser(char *str);
int setegroup(char *str);
int seteuser(char *str);
void strencode2(char *b, const char *text, int size);
void load_config_section(char *section, char **buffer, char *error);
void remove_crlf(char *buffer);
time_t convert_date(char *date_string);
time_t convert_datetime(char *date_string);
int get_thumb_name(const char *file_name, char *thumb_name, int size, int index);
int create_thumbnail(LOGBOOK * lbs, char *file_name);
int ascii_compare(const void *s1, const void *s2);
int ascii_compare2(const void *s1, const void *s2);
void do_crypt(const char *s, char *d, int size);
BOOL get_password_file(LOGBOOK * lbs, char *file_name, int size);

/* functions from auth.c */
int auth_verify_password(LOGBOOK *lbs, const char *user, const char *password);
int auth_change_password(LOGBOOK *lbs, const char *user, const char *old_pwd, const char *new_pwd, char *error_str, int error_size);
int auth_verify_password_krb5(LOGBOOK *lbs, const char *user, const char *password);
int auth_change_password_krb5(LOGBOOK *lbs, const char *user, const char *old_pwd, const char *new_pwd, char *error, int error_size);
