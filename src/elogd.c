/********************************************************************\

   Name:         elogd.c
   Created by:   Stefan Ritt
 
   Contents:     Web server program for Electronic Logbook ELOG
  
   $Log$
   Revision 1.240  2004/02/06 14:34:11  midas
   Sorting now also works for logbooks

   Revision 1.239  2004/02/05 07:58:38  midas
   Use send_tcp for large buffers

   Revision 1.238  2004/02/05 07:47:27  midas
   Fixed bug in search display for all logbooks

   Revision 1.237  2004/02/04 15:25:14  midas
   Fixed stack overflow in conjunction with 'use lock'

   Revision 1.236  2004/02/04 11:55:21  midas
   Display logbook in 'search all' even if 'list display' is present

   Revision 1.235  2004/02/04 10:39:22  midas
   Added 'js=xxx.js' support

   Revision 1.234  2004/02/04 09:21:37  midas
   Added 'use email heading edit'

   Revision 1.233  2004/02/04 08:25:06  midas
   Only [global] admin user sees 'synchronize all logbooks'

   Revision 1.232  2004/02/03 12:31:57  midas
   Changed typo

   Revision 1.231  2004/02/03 12:30:40  midas
   Changed typo

   Revision 1.230  2004/02/03 12:26:55  midas
   Change CRLF -> CR when saving elogd.cfg under Unix

   Revision 1.229  2004/02/03 10:36:17  midas
   Do not renumber and entries if they are already identical

   Revision 1.228  2004/02/03 10:10:50  midas
   Fixed missing logbook when language!=english

   Revision 1.227  2004/02/03 09:44:42  midas
   Fixed bug that 'save config' gave strange redirection

   Revision 1.226  2004/02/03 08:49:15  midas
   Fixed bug with conditional attributes

   Revision 1.225  2004/02/03 08:38:23  midas
   Validation now works with attributes containing blanks

   Revision 1.224  2004/02/02 21:13:06  midas
   Form validatin now also works for radio buttons

   Revision 1.223  2004/02/02 16:28:04  midas
   Added javascript for required attributes checking

   Revision 1.222  2004/02/02 16:00:01  midas
   Fixed bug that '<' was not correctly displayed in links

   Revision 1.221  2004/01/30 09:50:51  midas
   Added entry counter

   Revision 1.220  2004/01/30 09:25:17  midas
   Finished calendar in find form

   Revision 1.219  2004/01/29 21:20:02  midas
   Started working on calendar

   Revision 1.218  2004/01/29 09:53:27  midas
   Use \r\n in save_admin_config()

   Revision 1.217  2004/01/29 09:41:28  midas
   Implemented CSV output

   Revision 1.216  2004/01/28 15:27:18  midas
   Version 2.5.0

   Revision 1.215  2004/01/27 16:18:10  midas
   Use HTTP 1.0 in receive_message

   Revision 1.214  2004/01/27 13:45:05  midas
   Fixed bug in attachment retrieval

   Revision 1.213  2004/01/27 13:27:43  midas
   Remove email notification in submit_elog_mirror

   Revision 1.212  2004/01/27 11:22:56  midas
   Made cron work properly with 'wdays'

   Revision 1.211  2004/01/26 16:21:49  midas
   Revised logging for synchronizing

   Revision 1.210  2004/01/26 14:52:26  midas
   Added cron facility

   Revision 1.209  2004/01/23 16:35:18  midas
   Mirroring now works with top groups

   Revision 1.208  2004/01/22 21:19:09  midas
   Fixed mirror errors for replies

   Revision 1.207  2004/01/22 16:40:00  midas
   Keep attachment date/time on mirroring

   Revision 1.206  2004/01/22 12:29:48  midas
   Search 'all logbooks' only for current top group

   Revision 1.205  2004/01/21 16:25:07  midas
   Changed 'message' to 'entry' consistently

   Revision 1.204  2004/01/20 21:05:39  midas
   Synchronization almost works

   Revision 1.203  2004/01/20 16:25:57  midas
   Remove last CR in receive_message()

   Revision 1.202  2004/01/20 15:50:06  midas
   Changed error return from receive_message()

   Revision 1.201  2004/01/19 21:34:14  midas
   Implemented receive_message

   Revision 1.200  2004/01/19 16:22:28  midas
   Continued working on synchronization

   Revision 1.199  2004/01/19 09:13:28  midas
   Removed '{n}' in quick filter and find page list

   Revision 1.198  2004/01/18 21:47:11  midas
   Continued working on synchronizing

   Revision 1.197  2004/01/17 15:37:06  midas
   Display months on find page localized

   Revision 1.196  2004/01/16 20:41:34  midas
   Fixed language bug with 'change [global]'

   Revision 1.195  2004/01/16 19:43:30  midas
   Implemented setlocale() for strftime()

   Revision 1.194  2004/01/15 12:15:47  midas
   Fixed missing format_flags initialization

   Revision 1.193  2004/01/15 11:22:52  midas
   Fixed bug that boolean attributes were not accepted

   Revision 1.192  2004/01/14 20:08:24  midas
   Added 'expand all' facility

   Revision 1.191  2004/01/14 10:16:44  midas
   Added new translated strings

   Revision 1.190  2004/01/14 10:14:05  midas
   Changed layout when adding new options

   Revision 1.189  2004/01/14 10:04:17  midas
   Fixed bug of disappearing icons

   Revision 1.188  2004/01/13 21:24:42  midas
   Added 'extendable options'

   Revision 1.187  2004/01/13 16:37:27  midas
   Fixed bug with elog:/<n> referencing

   Revision 1.186  2004/01/13 15:15:48  midas
   Fixed disappearing text on edit

   Revision 1.185  2004/01/13 15:02:17  midas
   Sort user names in selection box

   Revision 1.184  2004/01/13 11:40:40  midas
   Fixed probelem with redirection

   Revision 1.183  2004/01/13 10:09:05  midas
   Fixed bug in get_logbook_hierarchy()

   Revision 1.182  2004/01/13 09:37:01  midas
   Admin users can edit [global <top>] section

   Revision 1.181  2004/01/12 08:37:17  midas
   Fixed bug that text disappeared upon upload

   Revision 1.180  2004/01/09 22:56:00  midas
   Implemented expansion in logbook selection page

   Revision 1.179  2004/01/09 14:57:58  midas
   Use '$entry date' instead of '$date' for 'Last submission'

   Revision 1.178  2004/01/09 14:34:58  midas
   Fixed bug in free_logbook_hierarchy()

   Revision 1.177  2004/01/09 14:21:56  midas
   Evaluate 'preset xxx' on re-edit

   Revision 1.176  2004/01/09 14:09:41  midas
   Added 'last submission' option

   Revision 1.175  2004/01/07 15:04:03  midas
   Check for duplicate logbooks

   Revision 1.174  2004/01/07 14:28:58  midas
   Added logging for SMTP communication

   Revision 1.173  2004/01/07 14:05:14  midas
   Fixed bug with permissions

   Revision 1.172  2004/01/07 11:14:36  midas
   Only section of current logbook can be edited in elogd.cfg

   Revision 1.171  2004/01/06 13:21:34  midas
   Changed indent style

   Revision 1.170  2004/01/05 15:02:14  midas
   Version 2.4.0

   Revision 1.169  2004/01/05 15:01:22  midas
   Display message comment on reedit

   Revision 1.168  2003/12/31 19:47:06  midas
   Implemented conditional attributes

   Revision 1.167  2003/12/15 09:36:23  midas
   Added 'date on reply = 2' option

   Revision 1.166  2003/12/05 12:16:23  midas
   Added .selframe style class

   Revision 1.165  2003/12/04 20:56:51  midas
   Added 'date on reply' flag

   Revision 1.164  2003/12/04 11:34:36  midas
   Made 'preset xxx' work with boolean attributes

   Revision 1.163  2003/12/03 14:36:01  midas
   Added 'comment <attribute>'

   Revision 1.162  2003/12/03 12:49:14  midas
   Changed email notification format

   Revision 1.161  2003/12/03 12:10:24  midas
   Change email notification format

   Revision 1.160  2003/12/03 11:55:27  midas
   Added 'use email heading'

   Revision 1.159  2003/11/27 10:15:39  midas
   Fixed bug with deny/allow commands in other languages

   Revision 1.158  2003/11/20 16:36:05  midas
   Added check_config_file()

   Revision 1.157  2003/11/20 16:22:54  midas
   Removed printf()

   Revision 1.156  2003/11/20 16:05:03  midas
   Implemented check_config

   Revision 1.155  2003/11/20 13:37:20  midas
   Added 'restrict edit time'

   Revision 1.154  2003/11/19 14:11:38  midas
   Added MAX_REPLY_TO

   Revision 1.153  2003/11/11 12:21:33  midas
   Fixed bug with \r and \n in header

   Revision 1.152  2003/11/11 12:11:19  midas
   Fixed stack overflow on long reply-chains

   Revision 1.151  2003/10/28 13:21:26  midas
   Fixed empty 'Location:' for konqueror

   Revision 1.150  2003/10/26 15:55:46  midas
   Fixed bug in el_delete_message

   Revision 1.149  2003/10/24 20:14:45  midas
   - user cannot change login name if already existing
   - user cannot search in logbooks of which he has no access
   - added date of last entry in logbook selection page

   Revision 1.148  2003/10/01 06:52:01  midas
   Started to implement synchronize

   Revision 1.147  2003/09/29 13:14:33  midas
   Create password file if not present

   Revision 1.146  2003/09/08 10:57:46  midas
   Fixed even more HTML errors

   Revision 1.145  2003/09/08 09:29:27  midas
   Fixed HTML errors with nested tables etc.

   Revision 1.144  2003/09/08 07:34:18  midas
   Increased timeout in SMTP conversation

   Revision 1.143  2003/09/05 15:16:21  midas
   Changed search for '\r' to '\n' in determination of reply line length

   Revision 1.142  2003/07/29 20:25:47  midas
   Fixed display of text attachments

   Revision 1.141  2003/07/28 15:24:27  midas
   Fixed bug with elog:/n reference

   Revision 1.140  2003/07/25 08:34:52  midas
   Fixed bugs in HTML code
                                          
\********************************************************************/

/* Version of ELOG */
#define VERSION "2.5.0"

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <locale.h>

#ifdef _MSC_VER

#define OS_WINNT

#define DIR_SEPARATOR '\\'
#define DIR_SEPARATOR_STR "\\"

#define snprintf _snprintf

#include <windows.h>
#include <io.h>
#include <time.h>
#include <direct.h>
#include <sys/stat.h>

#else

#define OS_UNIX

#define TRUE 1
#define FALSE 0

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

#define __USE_XOPEN             /* needed for crypt() */

typedef int BOOL;

#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <time.h>
#include <dirent.h>
#include <errno.h>
#include <ctype.h>
#include <pwd.h>
#include <grp.h>

#define closesocket(s) close(s)
#ifndef O_BINARY
#define O_BINARY 0
#endif

#define stricmp(s1, s2) strcasecmp(s1, s2)

gid_t orig_gid;                 /* Original effective GID before dropping privilege */
uid_t orig_uid;                 /* Original effective UID before dropping privilege */
#endif

char pidfile[256];              /* Pidfile name */

typedef int INT;

#define TELL(fh) lseek(fh, 0, SEEK_CUR)

#define NAME_LENGTH  500

#define DEFAULT_DATE_FORMAT "%#c"

#define SUCCESS        1

#define EL_SUCCESS     1
#define EL_FIRST_MSG   2
#define EL_LAST_MSG    3
#define EL_NO_MSG      4
#define EL_FILE_ERROR  5
#define EL_UPGRADE     6
#define EL_EMPTY       7
#define EL_MEM_ERROR   8
#define EL_DUPLICATE   9

#define EL_FIRST       1
#define EL_LAST        2
#define EL_NEXT        3
#define EL_PREV        4

char *return_buffer;
int return_buffer_size;
int strlen_retbuf;
int keep_alive;
char header_buffer[1000];
int return_length;
char host_name[256];
char referer[256];
char browser[256];
char config_file[256];
char resource_dir[256];
char logbook_dir[256];
char tcp_hostname[256];
int tcp_port = 80;
char theme_name[80];

#define MAX_GROUPS       32
#define MAX_PARAM       100
#define MAX_ATTACHMENTS  50
#define MAX_N_LIST      100
#define MAX_N_ATTR       50
#define MAX_REPLY_TO    100
#define CMD_SIZE      10000
#define TEXT_SIZE    250000
#define MAX_PATH_LENGTH 256

char _param[MAX_PARAM][NAME_LENGTH];
char _value[MAX_PARAM][NAME_LENGTH];
char _mtext[TEXT_SIZE];
char _cmdline[CMD_SIZE];
char *_attachment_buffer;
INT _attachment_size;
struct in_addr rem_addr;
char rem_host[256];
INT _sock;
BOOL verbose, use_keepalive, enable_execute = FALSE;
INT _current_message_id;
INT _logging_level;

char *mname[] = {
   "January",
   "February",
   "March",
   "April",
   "May",
   "June",
   "July",
   "August",
   "September",
   "October",
   "November",
   "December"
};

char type_list[MAX_N_LIST][NAME_LENGTH] = {
   "Routine",
   "Other"
};

char category_list[MAX_N_LIST][NAME_LENGTH] = {
   "General",
   "Other",
};

char author_list[MAX_N_LIST][NAME_LENGTH] = {
   ""
};

/* attribute flags */
#define AF_REQUIRED           (1<<0)
#define AF_LOCKED             (1<<1)
#define AF_MULTI              (1<<2)
#define AF_FIXED_EDIT         (1<<3)
#define AF_FIXED_REPLY        (1<<4)
#define AF_ICON               (1<<5)
#define AF_RADIO              (1<<6)
#define AF_EXTENDABLE         (1<<7)

/* attribute format flags */
#define AFF_SAME_LINE              1
#define AFF_MULTI_LINE             2
#define AFF_DATE                   4
#define AFF_EXTENDABLE             8

char attr_list[MAX_N_ATTR][NAME_LENGTH];
char attr_options[MAX_N_ATTR][MAX_N_LIST][NAME_LENGTH];
int attr_flags[MAX_N_ATTR];

char attr_list_default[][NAME_LENGTH] = {
   "Author",
   "Type",
   "Category",
   "Subject",
   ""
};

char attr_options_default[][MAX_N_LIST][NAME_LENGTH] = {
   {""},
   {"Routine", "Other"},
   {"General", "Other"},
   {""}
};

int attr_flags_default[] = {
   AF_REQUIRED,
   0,
   0,
   0
};


struct {
   char ext[32];
   char type[32];
} filetype[] = {

   {
   ".CSS", "text/css"}, {
   ".JPG", "image/jpeg"}, {
   ".JPEG", "image/jpeg"}, {
   ".GIF", "image/gif"}, {
   ".PNG", "image/png"}, {
   ".PS", "application/postscript"}, {
   ".EPS", "application/postscript"}, {
   ".HTML", "text/html"}, {
   ".HTM", "text/html"}, {
   ".XLS", "application/x-msexcel"}, {
   ".DOC", "application/msword"}, {
   ".PDF", "application/pdf"}, {
   ".JS", "application/x-javascript"}, {
   ".TXT", "text/plain"}, {
   ".ASC", "text/plain"}, {
   ".ZIP", "application/x-zip-compressed"}, {
""},};

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
   int in_reply_to;
} MSG_LIST;

LOGBOOK *lb_list = NULL;

void show_error(char *error);
BOOL enum_user_line(LOGBOOK * lbs, int n, char *user);
int get_user_line(char *logbook_name, char *user, char *password, char *full_name,
                  char *email, char *email_notify);
int strbreak(char *str, char list[][NAME_LENGTH], int size);
int execute_shell(LOGBOOK * lbs, int message_id, char attrib[MAX_N_ATTR][NAME_LENGTH],
                  char *sh_cmd);
BOOL isparam(char *param);
char *getparam(char *param);
void logf(LOGBOOK * lbs, const char *format, ...);
BOOL check_login_user(LOGBOOK * lbs, char *user);
LBLIST get_logbook_hierarchy(void);
int is_logbook_in_group(LBLIST pgrp, char *logbook);
void free_logbook_hierarchy(LBLIST root);
void show_top_text(LOGBOOK * lbs);
void show_bottom_text(LOGBOOK * lbs);

/*---- Funcions from the MIDAS library -----------------------------*/

BOOL equal_ustring(const char *str1, const char *str2)
{
   if (str1 == NULL && str2 != NULL)
      return FALSE;
   if (str1 != NULL && str2 == NULL)
      return FALSE;
   if (str1 == NULL && str2 == NULL)
      return TRUE;

   while (*str1)
      if (toupper(*str1++) != toupper(*str2++))
         return FALSE;

   if (*str2)
      return FALSE;

   return TRUE;
}

/*---- strlcpy and strlcat to avoid buffer overflow ----------------*/

/*
* Copy src to string dst of size siz.  At most siz-1 characters
* will be copied.  Always NUL terminates (unless size == 0).
* Returns strlen(src); if retval >= siz, truncation occurred.
*/
size_t strlcpy(char *dst, const char *src, size_t size)
{
   char *d = dst;
   const char *s = src;
   size_t n = size;

   /* Copy as many bytes as will fit */
   if (n != 0 && --n != 0) {
      do {
         if ((*d++ = *s++) == 0)
            break;
      } while (--n != 0);
   }

   /* Not enough room in dst, add NUL and traverse rest of src */
   if (n == 0) {
      if (size != 0)
         *d = '\0';             /* NUL-terminate dst */
      while (*s++);
   }

   return (s - src - 1);        /* count does not include NUL */
}

/*
* Appends src to string dst of size siz (unlike strncat, siz is the
* full size of dst, not space left).  At most siz-1 characters
* will be copied.  Always NUL terminates (unless size <= strlen(dst)).
* Returns strlen(src) + MIN(size, strlen(initial dst)).
* If retval >= size, truncation occurred.
*/
size_t strlcat(char *dst, const char *src, size_t size)
{
   char *d = dst;
   const char *s = src;
   size_t n = size;
   size_t dlen;

   /* Find the end of dst and adjust bytes left but don't go past end */
   while (n-- != 0 && *d != '\0')
      d++;
   dlen = d - dst;
   n = size - dlen;

   if (n == 0)
      return (dlen + strlen(s));
   while (*s != '\0') {
      if (n != 1) {
         *d++ = *s;
         n--;
      }
      s++;
   }
   *d = '\0';

   return (dlen + (s - src));   /* count does not include NUL */
}

/*-------------------------------------------------------------------*/

void strsubst(char *string, char name[][NAME_LENGTH], char value[][NAME_LENGTH], int n)
                                                      /* subsitute "$name" with value corresponding to name */
{
   int i, j;
   char tmp[1000], str[NAME_LENGTH], uattr[NAME_LENGTH], *ps, *pt, *p;

   pt = tmp;
   ps = string;
   for (p = strchr(ps, '$'); p != NULL; p = strchr(ps, '$')) {
      /* copy leading characters */
      j = (int) (p - ps);
      memcpy(pt, ps, j);
      pt += j;
      p++;

      /* extract name */
      strlcpy(str, p, sizeof(str));
      for (j = 0; j < (int) strlen(str); j++)
         str[j] = toupper(str[j]);

      /* search name */
      for (i = 0; i < n; i++) {
         strlcpy(uattr, name[i], sizeof(uattr));
         for (j = 0; j < (int) strlen(uattr); j++)
            uattr[j] = toupper(uattr[j]);

         if (strncmp(str, uattr, strlen(uattr)) == 0)
            break;
      }

      /* copy value */
      if (i < n) {
         strcpy(pt, value[i]);
         pt += strlen(pt);
         ps = p + strlen(uattr);
      } else {
         *pt++ = '$';
         ps = p;
      }
   }

   /* copy remainder */
   strcpy(pt, ps);

   /* return result */
   strcpy(string, tmp);
}

/*------------------------------------------------------------------*/

void url_decode(char *p)
/********************************************************************\
Decode the given string in-place by expanding %XX escapes
\********************************************************************/
{
   char *pD, str[3];
   int i;

   pD = p;
   while (*p) {
      if (*p == '%') {
         /* Escape: next 2 chars are hex representation of the actual character */
         p++;
         if (isxdigit(p[0]) && isxdigit(p[1])) {
            str[0] = p[0];
            str[1] = p[1];
            str[2] = 0;
            sscanf(p, "%02X", &i);

            *pD++ = (char) i;
            p += 2;
         } else
            *pD++ = '%';
      } else if (*p == '+') {
         /* convert '+' to ' ' */
         *pD++ = ' ';
         p++;
      } else {
         *pD++ = *p++;
      }
   }
   *pD = '\0';
}

void url_encode(char *ps, int size)
/********************************************************************\
Encode the given string in-place by adding %XX escapes
\********************************************************************/
{
   unsigned char *pd, *p, str[NAME_LENGTH];

   pd = str;
   p = ps;
   while (*p && (int) pd < (int) str + 250) {
      if (strchr(" %&=#?+", *p) || *p > 127) {
         sprintf(pd, "%%%02X", *p);
         pd += 3;
         p++;
      } else {
         *pd++ = *p++;
      }
   }
   *pd = '\0';
   strlcpy(ps, str, size);
}

/*-------------------------------------------------------------------*/

void btou(char *str)
/* convert all blanks to underscores in a string */
{
   int i;

   for (i = 0; i < (int) strlen(str); i++)
      if (str[i] == ' ')
         str[i] = '_';
}

/*-------------------------------------------------------------------*/

char *map = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

int cind(char c)
{
   int i;

   if (c == '=')
      return 0;

   for (i = 0; i < 64; i++)
      if (map[i] == c)
         return i;

   return -1;
}

void base64_decode(char *s, char *d)
{
   unsigned int t;

   while (*s) {
      t = (cind(*s++) << 18) | (cind(*s++) << 12) | (cind(*s++) << 6) | (cind(*s++) << 0);

      *(d + 2) = (char) (t & 0xFF);
      t >>= 8;
      *(d + 1) = (char) (t & 0xFF);
      t >>= 8;
      *d = (char) (t & 0xFF);

      d += 3;
   }
   *d = 0;
}

void base64_encode(char *s, char *d)
{
   unsigned int t, pad;

   pad = 3 - strlen(s) % 3;
   if (pad == 3)
      pad = 0;
   while (*s) {
      t = (*s++) << 16;
      if (*s)
         t |= (*s++) << 8;
      if (*s)
         t |= (*s++) << 0;

      *(d + 3) = map[t & 63];
      t >>= 6;
      *(d + 2) = map[t & 63];
      t >>= 6;
      *(d + 1) = map[t & 63];
      t >>= 6;
      *(d + 0) = map[t & 63];

      d += 4;
   }
   *d = 0;
   while (pad--)
      *(--d) = '=';
}

void base64_bufenc(unsigned char *s, int len, char *d)
{
   unsigned int t, pad;
   int i;

   pad = 3 - len % 3;
   if (pad == 3)
      pad = 0;
   for (i = 0; i < len;) {
      t = s[i++] << 16;
      if (i < len)
         t |= s[i++] << 8;
      if (i < len)
         t |= s[i++] << 0;

      *(d + 3) = map[t & 63];
      t >>= 6;
      *(d + 2) = map[t & 63];
      t >>= 6;
      *(d + 1) = map[t & 63];
      t >>= 6;
      *(d + 0) = map[t & 63];

      d += 4;
   }
   *d = 0;
   while (pad--)
      *(--d) = '=';
}

void do_crypt(char *s, char *d)
{
#ifdef HAVE_CRYPT
   strcpy(d, crypt(s, "el"));
#else
   base64_encode(s, d);
#endif
}

/*------------------------------------------------------------------*\
                                                   
   MD5 Checksum Routines
                                                    
\*------------------------------------------------------------------*/

typedef struct {
   unsigned int state[4];       // state (ABCD)
   unsigned int count[2];       // number of bits, modulo 2^64 (lsb first)
   unsigned char buffer[64];    // input buffer
} MD5_CONTEXT;

/*------------------------------------------------------------------*/

/* prototypes of the support routines */
void _MD5_update(MD5_CONTEXT *, const void *, unsigned int);
void _MD5_transform(unsigned int[4], unsigned char[64]);
void _MD5_encode(unsigned char *, unsigned int *, unsigned int);
void _MD5_decode(unsigned int *, unsigned char *, unsigned int);

/* F, G, H and I are basic MD5 functions */
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits */
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32-(n))))

/* FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4 */
/* Rotation is separate from addition to prevent recomputation */
#define FF(a, b, c, d, x, s, ac) {                  \
   (a) += F ((b), (c), (d)) + (x) + (unsigned int)(ac);  \
   (a) = ROTATE_LEFT ((a), (s));                   \
   (a) += (b);                                     \
                                                   }
#define GG(a, b, c, d, x, s, ac) {                  \
   (a) += G ((b), (c), (d)) + (x) + (unsigned int)(ac);  \
   (a) = ROTATE_LEFT ((a), (s));                   \
   (a) += (b);                                     \
                                                   }
#define HH(a, b, c, d, x, s, ac) {                  \
   (a) += H ((b), (c), (d)) + (x) + (unsigned int)(ac);  \
   (a) = ROTATE_LEFT ((a), (s));                   \
   (a) += (b);                                     \
                                                   }
#define II(a, b, c, d, x, s, ac) {                  \
   (a) += I ((b), (c), (d)) + (x) + (unsigned int)(ac);  \
   (a) = ROTATE_LEFT ((a), (s));                   \
   (a) += (b);                                     \
                                                   }

/*------------------------------------------------------------------*/

/* main MD5 checksum routine, returns digest from pdata buffer */

void MD5_checksum(const void *pdata, unsigned int len, unsigned char digest[16])
{
   MD5_CONTEXT ctx;
   unsigned char bits[8];
   unsigned int i, padlen;

   /* to allow multithreading we have to locate the padding memory here */
   unsigned char PADDING[64] = {
      0x80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
   };

   memset(&ctx, 0, sizeof(MD5_CONTEXT));
   ctx.count[0] = ctx.count[1] = 0;

   /* load magic initialization constants */
   ctx.state[0] = 0x67452301;
   ctx.state[1] = 0xefcdab89;
   ctx.state[2] = 0x98badcfe;
   ctx.state[3] = 0x10325476;

   _MD5_update(&ctx, pdata, len);

   // save number of bits
   _MD5_encode(bits, ctx.count, 8);

   // pad out to 56 mod 64
   i = (unsigned int) ((ctx.count[0] >> 3) & 0x3f);
   padlen = (i < 56) ? (56 - i) : (120 - i);
   _MD5_update(&ctx, PADDING, padlen);

   // append length (before padding)
   _MD5_update(&ctx, bits, 8);

   // store state in digest
   _MD5_encode(digest, ctx.state, 16);
}

/*------------------------------------------------------------------*/

void _MD5_update(MD5_CONTEXT * pctx, const void *pdata, unsigned int len)
{
   unsigned char *pin;
   unsigned int i, index, partlen;

   pin = (unsigned char *) pdata;

   // compute number of bytes mod 64
   index = (unsigned int) ((pctx->count[0] >> 3) & 0x3F);

   // update number of bits
   if ((pctx->count[0] += ((unsigned int) len << 3)) < ((unsigned int) len << 3))
      pctx->count[1]++;
   pctx->count[1] += ((unsigned int) len >> 29);

   partlen = 64 - index;

   // transform as many times as possible.
   if (len >= partlen) {
      memcpy(&pctx->buffer[index], pin, partlen);
      _MD5_transform(pctx->state, pctx->buffer);

      for (i = partlen; i + 63 < len; i += 64)
         _MD5_transform(pctx->state, &pin[i]);

      index = 0;
   } else
      i = 0;

   /* buffer remaining input */
   memcpy(&pctx->buffer[index], &pin[i], len - i);
}

/*------------------------------------------------------------------*/

/* basic transformation, transforms state based on block */
void _MD5_transform(unsigned int state[4], unsigned char block[64])
{
   unsigned int lA = state[0], lB = state[1], lC = state[2], lD = state[3];
   unsigned int x[16];

   _MD5_decode(x, block, 64);

   /* round 1 */
   FF(lA, lB, lC, lD, x[0], 7, 0xd76aa478);     // 1 
   FF(lD, lA, lB, lC, x[1], 12, 0xe8c7b756);    // 2 
   FF(lC, lD, lA, lB, x[2], 17, 0x242070db);    // 3 
   FF(lB, lC, lD, lA, x[3], 22, 0xc1bdceee);    // 4 
   FF(lA, lB, lC, lD, x[4], 7, 0xf57c0faf);     // 5 
   FF(lD, lA, lB, lC, x[5], 12, 0x4787c62a);    // 6 
   FF(lC, lD, lA, lB, x[6], 17, 0xa8304613);    // 7 
   FF(lB, lC, lD, lA, x[7], 22, 0xfd469501);    // 8 
   FF(lA, lB, lC, lD, x[8], 7, 0x698098d8);     // 9 
   FF(lD, lA, lB, lC, x[9], 12, 0x8b44f7af);    // 10 
   FF(lC, lD, lA, lB, x[10], 17, 0xffff5bb1);   // 11 
   FF(lB, lC, lD, lA, x[11], 22, 0x895cd7be);   // 12 
   FF(lA, lB, lC, lD, x[12], 7, 0x6b901122);    // 13 
   FF(lD, lA, lB, lC, x[13], 12, 0xfd987193);   // 14 
   FF(lC, lD, lA, lB, x[14], 17, 0xa679438e);   // 15 
   FF(lB, lC, lD, lA, x[15], 22, 0x49b40821);   // 16 

   /* round 2 */
   GG(lA, lB, lC, lD, x[1], 5, 0xf61e2562);     // 17 
   GG(lD, lA, lB, lC, x[6], 9, 0xc040b340);     // 18 
   GG(lC, lD, lA, lB, x[11], 14, 0x265e5a51);   // 19 
   GG(lB, lC, lD, lA, x[0], 20, 0xe9b6c7aa);    // 20 
   GG(lA, lB, lC, lD, x[5], 5, 0xd62f105d);     // 21 
   GG(lD, lA, lB, lC, x[10], 9, 0x2441453);     // 22 
   GG(lC, lD, lA, lB, x[15], 14, 0xd8a1e681);   // 23 
   GG(lB, lC, lD, lA, x[4], 20, 0xe7d3fbc8);    // 24 
   GG(lA, lB, lC, lD, x[9], 5, 0x21e1cde6);     // 25 
   GG(lD, lA, lB, lC, x[14], 9, 0xc33707d6);    // 26 
   GG(lC, lD, lA, lB, x[3], 14, 0xf4d50d87);    // 27 
   GG(lB, lC, lD, lA, x[8], 20, 0x455a14ed);    // 28 
   GG(lA, lB, lC, lD, x[13], 5, 0xa9e3e905);    // 29 
   GG(lD, lA, lB, lC, x[2], 9, 0xfcefa3f8);     // 30 
   GG(lC, lD, lA, lB, x[7], 14, 0x676f02d9);    // 31 
   GG(lB, lC, lD, lA, x[12], 20, 0x8d2a4c8a);   // 32 

   /* round 3 */
   HH(lA, lB, lC, lD, x[5], 4, 0xfffa3942);     // 33 
   HH(lD, lA, lB, lC, x[8], 11, 0x8771f681);    // 34 
   HH(lC, lD, lA, lB, x[11], 16, 0x6d9d6122);   // 35 
   HH(lB, lC, lD, lA, x[14], 23, 0xfde5380c);   // 36 
   HH(lA, lB, lC, lD, x[1], 4, 0xa4beea44);     // 37 
   HH(lD, lA, lB, lC, x[4], 11, 0x4bdecfa9);    // 38 
   HH(lC, lD, lA, lB, x[7], 16, 0xf6bb4b60);    // 39 
   HH(lB, lC, lD, lA, x[10], 23, 0xbebfbc70);   // 40 
   HH(lA, lB, lC, lD, x[13], 4, 0x289b7ec6);    // 41 
   HH(lD, lA, lB, lC, x[0], 11, 0xeaa127fa);    // 42 
   HH(lC, lD, lA, lB, x[3], 16, 0xd4ef3085);    // 43 
   HH(lB, lC, lD, lA, x[6], 23, 0x4881d05);     // 44 
   HH(lA, lB, lC, lD, x[9], 4, 0xd9d4d039);     // 45 
   HH(lD, lA, lB, lC, x[12], 11, 0xe6db99e5);   // 46 
   HH(lC, lD, lA, lB, x[15], 16, 0x1fa27cf8);   // 47 
   HH(lB, lC, lD, lA, x[2], 23, 0xc4ac5665);    // 48 

   /* round 4 */
   II(lA, lB, lC, lD, x[0], 6, 0xf4292244);     // 49 
   II(lD, lA, lB, lC, x[7], 10, 0x432aff97);    // 50 
   II(lC, lD, lA, lB, x[14], 15, 0xab9423a7);   // 51 
   II(lB, lC, lD, lA, x[5], 21, 0xfc93a039);    // 52 
   II(lA, lB, lC, lD, x[12], 6, 0x655b59c3);    // 53 
   II(lD, lA, lB, lC, x[3], 10, 0x8f0ccc92);    // 54 
   II(lC, lD, lA, lB, x[10], 15, 0xffeff47d);   // 55 
   II(lB, lC, lD, lA, x[1], 21, 0x85845dd1);    // 56 
   II(lA, lB, lC, lD, x[8], 6, 0x6fa87e4f);     // 57 
   II(lD, lA, lB, lC, x[15], 10, 0xfe2ce6e0);   // 58 
   II(lC, lD, lA, lB, x[6], 15, 0xa3014314);    // 59 
   II(lB, lC, lD, lA, x[13], 21, 0x4e0811a1);   // 60 
   II(lA, lB, lC, lD, x[4], 6, 0xf7537e82);     // 61 
   II(lD, lA, lB, lC, x[11], 10, 0xbd3af235);   // 62 
   II(lC, lD, lA, lB, x[2], 15, 0x2ad7d2bb);    // 63 
   II(lB, lC, lD, lA, x[9], 21, 0xeb86d391);    // 64 

   state[0] += lA;
   state[1] += lB;
   state[2] += lC;
   state[3] += lD;

   /* lClear sensitive information */
   memset(x, 0, sizeof(x));
}

/*------------------------------------------------------------------*/

/* encodes input (unsigned int) into output (unsigned char), 
   assumes that lLen is a multiple of 4 */
void _MD5_encode(unsigned char *pout, unsigned int *pin, unsigned int len)
{
   unsigned int i, j;

   for (i = 0, j = 0; j < len; i++, j += 4) {
      pout[j] = (unsigned char) (pin[i] & 0x0ff);
      pout[j + 1] = (unsigned char) ((pin[i] >> 8) & 0x0ff);
      pout[j + 2] = (unsigned char) ((pin[i] >> 16) & 0x0ff);
      pout[j + 3] = (unsigned char) ((pin[i] >> 24) & 0x0ff);
   }
}

/*------------------------------------------------------------------*/

/* encodes input (unsigned char) into output (unsigned int),
   assumes that lLen is a multiple of 4 */
void _MD5_decode(unsigned int *pout, unsigned char *pin, unsigned int len)
{
   unsigned int i, j;

   for (i = 0, j = 0; j < len; i++, j += 4)
      pout[i] = ((unsigned int) pin[j]) |
          (((unsigned int) pin[j + 1]) << 8) | (((unsigned int) pin[j + 2]) << 16) |
          (((unsigned int) pin[j + 3]) << 24);
}

/*------------------------------------------------------------------*/

/* Wrapper for setegid. */
int setgroup(char *str)
{
#ifdef OS_UNIX
   struct group *gr;

   gr = getgrnam(str);

   if (gr != NULL)
      if (setegid(gr->gr_gid) >= 0 && initgroups(gr->gr_name, gr->gr_gid) >= 0)
         return 0;
      else {
         printf("Cannot set effective GID to group \"%s\"\n", gr->gr_name);
         perror("setgroup");
   } else
      printf("Group \"%s\" not found\n", str);

   return -1;
#else
   return 0;
#endif
}

                                                   /* Wrapper for seteuid. */
int setuser(char *str)
{
#ifdef OS_UNIX
   struct passwd *pw;

   pw = getpwnam(str);

   if (pw != NULL)
      if (seteuid(pw->pw_uid) >= 0)
         return 0;
      else {
         printf("Cannot set effective UID to user \"%s\"\n", str);
         perror("setuser");
   } else
      printf("User \"%s\" not found\n", str);

   return -1;
#else
   return 0;
#endif
}

/*-------------------------------------------------------------------*/

INT recv_string(int sock, char *buffer, INT buffer_size, INT millisec)
{
   INT i, n;
   fd_set readfds;
   struct timeval timeout;

   n = 0;
   memset(buffer, 0, buffer_size);

   do {
      if (millisec > 0) {
         FD_ZERO(&readfds);
         FD_SET(sock, &readfds);

         timeout.tv_sec = millisec / 1000;
         timeout.tv_usec = (millisec % 1000) * 1000;

         select(FD_SETSIZE, (void *) &readfds, NULL, NULL, (void *) &timeout);

         if (!FD_ISSET(sock, &readfds))
            break;
      }

      i = recv(sock, buffer + n, 1, 0);

      if (i <= 0)
         break;

      n++;

      if (n >= buffer_size)
         break;

   } while (buffer[n - 1] && buffer[n - 1] != 10);

   return n - 1;
}

/*-------------------------------------------------------------------*/

INT sendmail(LOGBOOK * lbs, char *smtp_host, char *from, char *to,
             char *subject, char *text, BOOL email_to, char *url,
             char att_file[MAX_ATTACHMENTS][256])
{
   struct sockaddr_in bind_addr;
   struct hostent *phe;
   int i, n, s, offset, strsize, n_att, index, fh;
   char buf[80];
   char *str, *p, boundary[256], file_name[MAX_PATH_LENGTH];
   time_t now;
   struct tm *ts;
   char list[1024][NAME_LENGTH], buffer[256];

   if (verbose)
      printf("\n\nEmail from %s to %s, SMTP host %s:\n", from, to, smtp_host);
   logf(lbs, "Email from %s to %s, SMTP host %s:\n", from, to, smtp_host);

   /* count attachments */
   n_att = 0;
   if (att_file)
      for (n_att = 0; att_file[n_att][0] && n_att < MAX_ATTACHMENTS; n_att++);

   /* create a new socket for connecting to remote server */
   s = socket(AF_INET, SOCK_STREAM, 0);
   if (s == -1)
      return -1;

   /* connect to remote node port 25 */
   memset(&bind_addr, 0, sizeof(bind_addr));
   bind_addr.sin_family = AF_INET;
   bind_addr.sin_port = htons((short) 25);

   phe = gethostbyname(smtp_host);
   if (phe == NULL)
      return -1;
   memcpy((char *) &(bind_addr.sin_addr), phe->h_addr, phe->h_length);

   if (connect(s, (void *) &bind_addr, sizeof(bind_addr)) < 0) {
      closesocket(s);
      return -1;
   }

   strsize = TEXT_SIZE + 1000;
   str = malloc(strsize);

   recv_string(s, str, strsize, 10000);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   /* drain server messages */
   do {
      str[0] = 0;
      recv_string(s, str, strsize, 300);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);
   } while (str[0]);

   snprintf(str, strsize - 1, "HELO %s\r\n", host_name);
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);
   recv_string(s, str, strsize, 3000);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   snprintf(str, strsize - 1, "MAIL FROM: <%s>\r\n", from);
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);
   recv_string(s, str, strsize, 3000);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   /* break recipients into list */
   n = strbreak(to, list, 1024);

   for (i = 0; i < n; i++) {
      snprintf(str, strsize - 1, "RCPT TO: <%s>\r\n", list[i]);
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);

      /* increased timeout for SMTP servers with long alias lists */
      recv_string(s, str, strsize, 30000);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);
   }

   snprintf(str, strsize - 1, "DATA\r\n");
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);
   recv_string(s, str, strsize, 3000);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   if (email_to)
      snprintf(str, strsize - 1, "To: %s\r\n", to);
   else
      snprintf(str, strsize - 1, "To: ELOG user\r\n");

   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   snprintf(str, strsize - 1, "From: %s\r\nSubject: %s\r\n", from, subject);
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   snprintf(str, strsize - 1, "X-Mailer: Elog, Version %s\r\n", VERSION);
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   if (url) {
      snprintf(str, strsize - 1, "X-Elog-URL: %s\r\n", url);
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);
   }

   snprintf(str, strsize - 1, "X-Elog-submit-type: web|elog\r\n");
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   time(&now);
   ts = localtime(&now);
   strftime(buf, sizeof(buf), "%a, %d %b %Y %H:%M:%S", ts);
   offset = (-(int) timezone);
   if (ts->tm_isdst)
      offset += 3600;
   snprintf(str, strsize - 1, "Date: %s %+03d%02d\r\n", buf, (int) (offset / 3600),
            (int) ((abs((int) offset) / 60) % 60));
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   if (n_att > 0) {
      snprintf(str, strsize - 1, "MIME-Version: 1.0\r\n");
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);

      sprintf(boundary, "%04X-%04X=:%04X", rand(), rand(), rand());
      snprintf(str, strsize - 1, "Content-Type: MULTIPART/MIXED; BOUNDARY=\"%s\"\r\n\r\n",
               boundary);
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);

      snprintf(str, strsize - 1,
               "  This message is in MIME format.  The first part should be readable text,\r\n");
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);

      snprintf(str, strsize - 1,
               "  while the remaining parts are likely unreadable without MIME-aware tools.\r\n\r\n");
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);

      snprintf(str, strsize - 1,
               "--%s\r\nContent-Type: TEXT/PLAIN; charset=US-ASCII\r\n\r\n", boundary);
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);
   } else {
      snprintf(str, strsize - 1, "Content-Type: TEXT/PLAIN; charset=US-ASCII\r\n\r\n");
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);
   }

   /* analyze text for "." at beginning of line */
   p = text;
   str[0] = 0;
   while (strstr(p, "\r\n.\r\n")) {
      i = (int) strstr(p, "\r\n.\r\n") - (int) p + 1;
      strlcat(str, p, i);
      p += i + 4;
      strlcat(str, "\r\n..\r\n", strsize);
   }
   strlcat(str, p, strsize);
   strlcat(str, "\r\n\r\n", strsize);
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);

   if (n_att > 0) {
      snprintf(str, strsize - 1, "--%s\r\n", boundary);
      send(s, str, strlen(str), 0);
      if (verbose)
         fputs(str, stdout);
      logf(lbs, str);

      for (index = 0; index < n_att; index++) {
         /* return proper Content-Type for file type */
         for (i = 0; i < (int) strlen(att_file[index]); i++)
            str[i] = toupper(att_file[index][i]);
         str[i] = 0;

         for (i = 0; filetype[i].ext[0]; i++)
            if (strstr(str, filetype[i].ext))
               break;

         if (filetype[i].ext[0])
            snprintf(str, strsize - 1, "Content-Type: %s; name=\"%s\"\r\n",
                     filetype[i].type, att_file[index] + 14);
         else if (strchr(str, '.') == NULL)
            snprintf(str, strsize - 1, "Content-Type: text/plain; name=\"%s\"\r\n",
                     att_file[index] + 14);
         else
            snprintf(str, strsize - 1,
                     "Content-Type: application/octet-stream; name=\"%s\"\r\n",
                     att_file[index] + 14);

         send(s, str, strlen(str), 0);
         if (verbose)
            fputs(str, stdout);
         logf(lbs, str);

         snprintf(str, strsize - 1, "Content-Transfer-Encoding: BASE64\r\n");
         send(s, str, strlen(str), 0);
         if (verbose)
            fputs(str, stdout);
         logf(lbs, str);

         snprintf(str, strsize - 1,
                  "Content-Disposition: attachment; filename=\"%s\"\r\n\r\n",
                  att_file[index] + 14);
         send(s, str, strlen(str), 0);
         if (verbose)
            fputs(str, stdout);
         logf(lbs, str);

         /* encode file */
         strlcpy(file_name, lbs->data_dir, sizeof(file_name));
         strlcat(file_name, att_file[index], sizeof(file_name));

         fh = open(file_name, O_RDONLY | O_BINARY);
         if (fh > 0) {
            do {
               n = read(fh, buffer, 45);
               if (n <= 0)
                  break;

               base64_bufenc(buffer, n, str);
               strcat(str, "\r\n");
               send(s, str, strlen(str), 0);
               if (verbose)
                  fputs(str, stdout);
            } while (1);

            close(fh);
         }

         /* send boundary */
         if (index < n_att - 1)
            snprintf(str, strsize - 1, "\r\n--%s\r\n", boundary);
         else
            snprintf(str, strsize - 1, "\r\n--%s--\r\n", boundary);

         send(s, str, strlen(str), 0);
         if (verbose)
            fputs(str, stdout);
         logf(lbs, str);
      }
   }

   /* send ".<CR>" to signal end of message */
   snprintf(str, strsize - 1, ".\r\n");
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   recv_string(s, str, strsize, 3000);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   snprintf(str, strsize - 1, "QUIT\r\n");
   send(s, str, strlen(str), 0);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);
   recv_string(s, str, strsize, 3000);
   if (verbose)
      fputs(str, stdout);
   logf(lbs, str);

   closesocket(s);
   free(str);

   return 1;
}

/*-------------------------------------------------------------------*/

void split_url(char *url, char *host, int *port, char *subdir, char *param)
{
   char *p;

   host[0] = subdir[0] = param[0] = 0;
   *port = 80;

   p = url;
   if (strncmp(url, "http://", 7) == 0)
      p += 7;

   strncpy(host, p, 256);
   if (strchr(host, '/')) {
      strncpy(subdir, strchr(host, '/'), 256);
      *strchr(host, '/') = 0;
   }

   if (strchr(host, '?')) {
      strncpy(subdir, strchr(host, '?'), 256);
      *strchr(host, '?') = 0;
   }

   if (strchr(host, ':')) {
      *port = atoi(strchr(host, ':') + 1);
      *strchr(host, ':') = 0;
   }

   if (strchr(subdir, '?')) {
      strncpy(param, strchr(subdir, '?'), 256);
      *strchr(subdir, '?') = 0;
   }

   if (subdir[0] == 0)
      strcpy(subdir, "/");
}

/*-------------------------------------------------------------------*/

int retrieve_url(char *url, char **buffer)
{
   struct sockaddr_in bind_addr;
   struct hostent *phe;
   char str[256], host[256], subdir[256], param[256];
   int port, sock, bufsize;
   INT i, n;
   fd_set readfds;
   struct timeval timeout;

   *buffer = NULL;
   split_url(url, host, &port, subdir, param);

   /* create a new socket for connecting to remote server */
   sock = socket(AF_INET, SOCK_STREAM, 0);
   if (sock == -1)
      return -1;

   /* connect to remote node */
   memset(&bind_addr, 0, sizeof(bind_addr));
   bind_addr.sin_family = AF_INET;
   bind_addr.sin_port = htons((short) port);

   phe = gethostbyname(host);
   if (phe == NULL)
      return -1;
   memcpy((char *) &(bind_addr.sin_addr), phe->h_addr, phe->h_length);

   if (connect(sock, (void *) &bind_addr, sizeof(bind_addr)) < 0) {
      closesocket(sock);
      return -1;
   }

   /* compose GET request, avoid chunked data in HTTP/1.1 protocol */
   sprintf(str, "GET %s%s HTTP/1.0\r\nConnection: Close\r\n", subdir, param);

   /* add local username/password */
   if (isparam("unm"))
      sprintf(str + strlen(str), "Cookie: unm=%s; upwd=%s\r\n", getparam("unm"),
              getparam("upwd"));

   /* add host (RFC2616, Sec. 14) */
   sprintf(str + strlen(str), "Host: %s:%d\r\n", host, port);

   strcat(str, "\r\n");

   send(sock, str, strlen(str), 0);

   bufsize = TEXT_SIZE + 1000;
   *buffer = malloc(bufsize);
   memset(*buffer, 0, bufsize);

   n = 0;

   do {
      FD_ZERO(&readfds);
      FD_SET(sock, &readfds);

      timeout.tv_sec = 30;      /* 30 sec. timeout */
      timeout.tv_usec = 0;

      select(FD_SETSIZE, (void *) &readfds, NULL, NULL, (void *) &timeout);

      if (!FD_ISSET(sock, &readfds)) {
         closesocket(sock);
         free(buffer);
         buffer = NULL;
         return -1;
      }

      i = recv(sock, *buffer + n, bufsize - n, 0);

      if (i <= 0)
         break;

      n += i;

      if (n >= bufsize) {
         /* increase buffer size */
         bufsize += 10000;
         *buffer = realloc(*buffer, bufsize);
         if (*buffer == NULL) {
            closesocket(sock);
            return -1;
         }
      }

   } while (1);

   closesocket(sock);



   return n;
}

/*-------------------------------------------------------------------*/

INT ss_daemon_init()
{
#ifdef OS_UNIX

   /* only implemented for UNIX */
   int i, fd, pid;

   if ((pid = fork()) < 0)
      return 0;
   else if (pid != 0)
      exit(EXIT_SUCCESS);       /* parent finished */

   /* child continues here */

   /* try and use up stdin, stdout and stderr, so other
      routines writing to stdout etc won't cause havoc. Copied from smbd */
   for (i = 0; i < 3; i++) {
      close(i);
      fd = open("/dev/null", O_RDWR, 0);
      if (fd < 0)
         fd = open("/dev/null", O_WRONLY, 0);
      if (fd < 0) {
         printf("Can't open /dev/null");
         return 0;
      }
      if (fd != i) {
         printf("Did not get file descriptor");
         return 0;
      }
   }

   setsid();                    /* become session leader */
   chdir("/");                  /* change working direcotry (not on NFS!) */
   umask(0);                    /* clear our file mode creation mask */

#endif

   return SUCCESS;
}

/*------------------------------------------------------------------*/

/* Parameter extraction from configuration file similar to win.ini */

char *cfgbuffer;
time_t cfgfile_mtime = 0;

/*-------------------------------------------------------------------*/

void check_config_file()
{
   struct stat cfg_stat;

   /* force re-read configuration file if changed */
   if (stat(config_file, &cfg_stat) == 0) {
      if (cfgfile_mtime < cfg_stat.st_mtime) {
         cfgfile_mtime = cfg_stat.st_mtime;

         if (cfgbuffer) {
            free(cfgbuffer);
            cfgbuffer = NULL;
         }
      }
   } else {
      perror("Cannot stat() config file");
   }
}

/*-------------------------------------------------------------------*/

char _topgroup[256];

void setcfg_topgroup(char *topgroup)
{
   strcpy(_topgroup, topgroup);
}

char *getcfg_topgroup()
{
   if (_topgroup[0])
      return _topgroup;

   return NULL;
}

/*------------------------------------------------------------------*/

int is_logbook(char *logbook)
{
   char str[256];

   strlcpy(str, logbook, sizeof(str));
   str[6] = 0;
   return !equal_ustring(str, "global");
}

/*-------------------------------------------------------------------*/

int getcfg_simple(char *group, char *param, char *value)
/* read value for certain parameter in configuration file using [<group>] */
{
   char *str, *p, *pstr;
   int length;
   int fh;

   value[0] = 0;

   /* read configuration file on init */
   if (!cfgbuffer) {
      fh = open(config_file, O_RDONLY | O_BINARY);
      if (fh < 0)
         return 0;
      length = lseek(fh, 0, SEEK_END);
      lseek(fh, 0, SEEK_SET);
      cfgbuffer = malloc(length + 1);
      if (cfgbuffer == NULL) {
         close(fh);
         return 0;
      }
      read(fh, cfgbuffer, length);
      cfgbuffer[length] = 0;
      close(fh);
   }

   /* search group */
   str = malloc(10000);
   p = cfgbuffer;
   do {
      if (*p == '[') {
         p++;
         pstr = str;
         while (*p && *p != ']' && *p != '\n')
            *pstr++ = *p++;
         *pstr = 0;
         if (equal_ustring(str, group)) {
            /* search parameter */
            p = strchr(p, '\n');
            if (p)
               p++;
            while (p && *p && *p != '[') {
               pstr = str;
               while (*p && *p != '=' && *p != '\n')
                  *pstr++ = *p++;
               *pstr-- = 0;
               while (pstr > str && (*pstr == ' ' || *pstr == '=' || *pstr == '\t'))
                  *pstr-- = 0;

               if (equal_ustring(str, param)) {
                  if (*p == '=') {
                     p++;
                     while (*p == ' ' || *p == '\t')
                        p++;
                     pstr = str;
                     while (*p && *p != '\n' && *p != '\r')
                        *pstr++ = *p++;
                     *pstr-- = 0;
                     while (*pstr == ' ' || *pstr == '\t')
                        *pstr-- = 0;

                     if (str[0] == '"' && str[strlen(str) - 1] == '"') {
                        strcpy(value, str + 1);
                        value[strlen(value) - 1] = 0;
                     } else
                        strcpy(value, str);

                     free(str);
                     return 1;
                  }
               }

               if (p)
                  p = strchr(p, '\n');
               if (p)
                  p++;
            }
         }
      }
      if (p)
         p = strchr(p, '\n');
      if (p)
         p++;
   } while (p);


   free(str);

   return 0;
}

/*-------------------------------------------------------------------*/

int getcfg(char *group, char *param, char *value)
/* 
   Read parameter from configuration file.
   
   - if group == [global] and top group exists, read
     from [global <top group>]

   - if parameter not in [global <top group>], read from [global]

   - if group is logbook, read from logbook section

   - if parameter not in [<logbook>], read from [global <top group>]
     or [global]
*/
{
   char str[256];
   int status;

   /* if group is [global] and top group exists, read from there */
   if (equal_ustring(group, "global") && getcfg_topgroup()) {
      sprintf(str, "global %s", getcfg_topgroup());
      if (getcfg(str, param, value))
         return 1;
   }

   status = getcfg_simple(group, param, value);
   if (status)
      return status;

   /* if parameter not found in logbook, look in [global] section */
   if (!group || is_logbook(group))
      return getcfg("global", param, value);

   return 0;
}

/*-------------------------------------------------------------------*/

char *find_param(char *buf, char *group, char *param)
{
   char *str, *p, *pstr, *pstart;

   /* search group */
   str = malloc(10000);
   p = buf;
   do {
      if (*p == '[') {
         p++;
         pstr = str;
         while (*p && *p != ']' && *p != '\n')
            *pstr++ = *p++;
         *pstr = 0;
         if (equal_ustring(str, group)) {
            /* search parameter */
            p = strchr(p, '\n');
            if (p)
               p++;
            while (p && *p && *p != '[') {
               pstr = str;
               pstart = p;
               while (*p && *p != '=' && *p != '\n')
                  *pstr++ = *p++;
               *pstr-- = 0;
               while (pstr > str && (*pstr == ' ' || *pstr == '=' || *pstr == '\t'))
                  *pstr-- = 0;

               if (equal_ustring(str, param)) {
                  free(str);
                  return pstart;
               }

               if (p)
                  p = strchr(p, '\n');
               if (p)
                  p++;
            }
         }
      }
      if (p)
         p = strchr(p, '\n');
      if (p)
         p++;
   } while (p);


   free(str);

   return NULL;
}

/*-------------------------------------------------------------------*/

int is_group(char *group)
{
   char *str, *p, *pstr;

   /* search group */
   str = malloc(10000);
   p = cfgbuffer;
   do {
      if (*p == '[') {
         p++;
         pstr = str;
         while (*p && *p != ']' && *p != '\n')
            *pstr++ = *p++;
         *pstr = 0;
         if (equal_ustring(str, group)) {
            free(str);
            return 1;
         }
      }
      if (p)
         p = strchr(p, '\n');
      if (p)
         p++;
   } while (p);


   free(str);
   return 0;
}

/*------------------------------------------------------------------*/

int getcfg_cond(char *group, char *condition, char *param, char *value)
{
   char str[256];

   if (condition == NULL || condition[0] == 0)
      return getcfg(group, param, value);

   sprintf(str, "{%s}%s", condition, param);
   if (getcfg(group, str, value))
      return 2;

   sprintf(str, "{%s} %s", condition, param);
   if (getcfg(group, str, value))
      return 2;

   return getcfg(group, param, value);
}

/*------------------------------------------------------------------*/

int enumcfg(char *group, char *param, char *value, int index)
{
   char str[10000], *p, *pstr;
   int i;

   /* open configuration file */
   if (!cfgbuffer)
      getcfg("dummy", "dummy", str);
   if (!cfgbuffer)
      return 0;

   /* search group */
   p = cfgbuffer;
   do {
      if (*p == '[') {
         p++;
         pstr = str;
         while (*p && *p != ']' && *p != '\n' && *p != '\r')
            *pstr++ = *p++;
         *pstr = 0;
         if (equal_ustring(str, group)) {
            /* enumerate parameters */
            i = 0;
            p = strchr(p, '\n');
            if (p)
               p++;
            while (p && *p && *p != '[') {
               pstr = str;
               while (*p && *p != '=' && *p != '\n' && *p != '\r')
                  *pstr++ = *p++;
               *pstr-- = 0;
               while (pstr > str && (*pstr == ' ' || *pstr == '\t' || *pstr == '='))
                  *pstr-- = 0;

               if (i == index) {
                  strcpy(param, str);
                  if (*p == '=') {
                     p++;
                     while (*p == ' ' || *p == '\t')
                        p++;
                     pstr = str;
                     while (*p && *p != '\n' && *p != '\r')
                        *pstr++ = *p++;
                     *pstr-- = 0;
                     while (*pstr == ' ' || *pstr == '\t')
                        *pstr-- = 0;

                     if (value)
                        strcpy(value, str);
                  }
                  return 1;
               }

               if (p)
                  p = strchr(p, '\n');
               if (p)
                  p++;
               i++;
            }
         }
      }
      if (p)
         p = strchr(p, '\n');
      if (p)
         p++;
   } while (p);

   return 0;
}

/*------------------------------------------------------------------*/

int enumgrp(int index, char *group)
{
   char str[10000], *p, *pstr;
   int i;

   /* open configuration file */
   if (!cfgbuffer)
      getcfg("dummy", "dummy", str);
   if (!cfgbuffer)
      return 0;

   /* search group */
   p = cfgbuffer;
   i = 0;
   do {
      if (*p == '[') {
         p++;
         pstr = str;
         while (*p && *p != ']' && *p != '\n' && *p != '\r')
            *pstr++ = *p++;
         *pstr = 0;

         if (i == index) {
            strcpy(group, str);
            return 1;
         }

         i++;
      }

      while (*p && *p != '\r' && *p != '\n')
         p++;
      while (*p && (*p == '\r' || *p == '\n'))
         p++;
   } while (*p);

   return 0;
}

/*-------------------------------------------------------------------*/

int exist_top_group()
{
   int i;
   char str[256];

   for (i = 0;; i++) {
      if (!enumcfg("global", str, NULL, i))
         break;
      str[9] = 0;
      if (equal_ustring(str, "top group"))
         return 1;
   }

   return 0;
}

/*-------------------------------------------------------------------*/

char *_locbuffer = NULL;
char **_porig, **_ptrans;
time_t _locfile_mtime = 0;

/* check if language file changed and if so reload it */
int check_language()
{
   char language[256], file_name[256], *p;
   int fh, length, n;
   struct stat cfg_stat;

   getcfg("global", "Language", language);

   /* set locale for strftime */
   if (language[0])
      setlocale(LC_ALL, language);
   else
      setlocale(LC_ALL, "english");

   /* force re-read configuration file if changed */
   strlcpy(file_name, resource_dir, sizeof(file_name));
   strlcat(file_name, "eloglang.", sizeof(file_name));
   strlcat(file_name, language, sizeof(file_name));

   if (stat(file_name, &cfg_stat) == 0) {
      if (_locfile_mtime != cfg_stat.st_mtime) {
         _locfile_mtime = cfg_stat.st_mtime;

         if (_locbuffer) {
            free(_locbuffer);
            _locbuffer = NULL;
         }
      }
   }

   if (equal_ustring(language, "english") || language[0] == 0) {
      if (_locbuffer) {
         free(_locbuffer);
         _locbuffer = NULL;
      }
   } else {
      if (_locbuffer == NULL) {
         fh = open(file_name, O_RDONLY | O_BINARY);
         if (fh < 0)
            return -1;

         length = lseek(fh, 0, SEEK_END);
         lseek(fh, 0, SEEK_SET);
         _locbuffer = malloc(length + 1);
         if (_locbuffer == NULL) {
            close(fh);
            return -1;
         }
         read(fh, _locbuffer, length);
         _locbuffer[length] = 0;
         close(fh);

         /* scan lines, setup orig-translated pointers */
         p = _locbuffer;
         n = 0;
         do {
            while (*p && (*p == '\r' || *p == '\n'))
               p++;

            if (*p && (*p == ';' || *p == '#' || *p == ' ' || *p == '\t')) {
               while (*p && *p != '\n' && *p != '\r')
                  p++;
               continue;
            }

            if (n == 0) {
               _porig = malloc(sizeof(char *) * 2);
               _ptrans = malloc(sizeof(char *) * 2);
            } else {
               _porig = realloc(_porig, sizeof(char *) * (n + 2));
               _ptrans = realloc(_ptrans, sizeof(char *) * (n + 2));
            }

            _porig[n] = p;
            while (*p && (*p != '=' && *p != '\r' && *p != '\n'))
               p++;

            if (*p && *p != '=')
               continue;

            _ptrans[n] = p + 1;
            while (*_ptrans[n] == ' ' || *_ptrans[n] == '\t')
               _ptrans[n]++;

            /* remove '=' and surrounding blanks */
            while (*p == '=' || *p == ' ' || *p == '\t')
               *p-- = 0;

            p = _ptrans[n];
            while (*p && *p != '\n' && *p != '\r')
               p++;

            if (p)
               *p++ = 0;

            n++;
         } while (p && *p);

         _porig[n] = NULL;
         _ptrans[n] = NULL;
      }
   }

   return 0;
}

/*-------------------------------------------------------------------*/

/* localization support */
char *loc(char *orig)
{
   int n;
   char language[256];
   static char result[256];

   if (!_locbuffer)
      return orig;

   /* search string and return translation */
   for (n = 0; _porig[n]; n++)
      if (strcmp(orig, _porig[n]) == 0) {
         if (*_ptrans[n])
            return _ptrans[n];
         return orig;
      }

   /* special case: "Change %s" */
   if (strstr(orig, "Change ") && strcmp(orig, "Change %s") != 0) {
      sprintf(result, loc("Change %s"), orig + 7);
      return result;
   }


   getcfg("global", "Language", language);
   printf("Language error: string \"%s\" not found for language \"%s\"\n", orig,
          language);

   return orig;
}

/*-------------------------------------------------------------------*/

/* translate back from localized string to english */

char *unloc(char *orig)
{
   int n;

   if (!_locbuffer)
      return orig;

   /* search string and return translation */
   for (n = 0; _ptrans[n]; n++)
      if (strcmp(orig, _ptrans[n]) == 0) {
         if (*_porig[n])
            return _porig[n];
         return orig;
      }

   printf("Language error: string \"%s\" not found in English\n", orig);

   return orig;
}

/*-------------------------------------------------------------------*/

char *month_name(int m)
/* return name of month in current locale, m=0..11 */
{
   struct tm ts;
   static char name[32];

   memset(&ts, 0, sizeof(ts));
   ts.tm_mon = m;
   ts.tm_mday = 15;
   ts.tm_year = 2000;

   mktime(&ts);
   strftime(name, sizeof(name), "%B", &ts);
   return name;
}

/*-------------------------------------------------------------------*/

void check_config()
{
   check_config_file();
   check_language();
}

/*------------------------------------------------------------------*/

void el_decode(char *message, char *key, char *result)
{
   char *pc, *ph;

   if (result == NULL)
      return;

   *result = 0;

   ph = strstr(message, "========================================");
   if (ph == NULL)
      return;

   do {
      if (ph[40] == '\r' || ph[40] == '\n')
         break;
      ph = strstr(ph + 40, "========================================");
      if (ph == NULL)
         return;

   } while (1);

   if ((pc = strstr(message, key)) != NULL && pc < ph
       && (*(pc - 1) == '\n' || *(pc - 1) == '\r')) {
      for (pc = strstr(message, key) + strlen(key); *pc != '\n' && *pc != '\r';)
         *result++ = *pc++;
      *result = 0;
   } else
      *result = 0;
}

/*------------------------------------------------------------------*/

void el_enum_attr(char *message, int n, char *attr_name, char *attr_value)
{
   char *p, str[NAME_LENGTH], tmp[NAME_LENGTH];
   int i;

   p = message;
   for (i = 0; i <= n; i++) {
      strlcpy(str, p, sizeof(str));
      if (strchr(str, '\n'))
         *strchr(str, '\n') = 0;
      if (strchr(str, '\r'))
         *strchr(str, '\r') = 0;

      if (strcmp(str, "========================================") == 0)
         break;

      p = strchr(p, '\n');
      if (!p)
         break;
      while (*p == '\n' || *p == '\r')
         p++;

      if (strchr(str, ':')) {
         strcpy(tmp, str);
         *strchr(tmp, ':') = 0;

         if (equal_ustring(tmp, "$@MID@$") ||
             equal_ustring(tmp, "Date") ||
             equal_ustring(tmp, "Attachment") ||
             equal_ustring(tmp, "Reply To") ||
             equal_ustring(tmp, "In Reply To") ||
             equal_ustring(tmp, "Encoding") || equal_ustring(tmp, "Locked by"))
            i--;
      }
   }

   attr_name[0] = 0;
   attr_value[0] = 0;
   if (strchr(str, ':')) {
      strlcpy(attr_name, str, NAME_LENGTH);
      *strchr(attr_name, ':') = 0;
      strlcpy(attr_value, strchr(str, ':') + 2, NAME_LENGTH);
   }

}

/*------------------------------------------------------------------*/

/* Simplified copy of fnmatch() for Cygwin where fnmatch is not defined */

#define EOS '\0'

int fnmatch1(const char *pattern, const char *string)
{
   const char *stringstart;
   char c, test;

   for (stringstart = string;;)
      switch (c = *pattern++) {
      case EOS:
         return (*string == EOS ? 0 : 1);
      case '?':
         if (*string == EOS)
            return (1);
         ++string;
         break;
      case '*':
         c = *pattern;
         /* Collapse multiple stars. */
         while (c == '*')
            c = *++pattern;

         /* Optimize for pattern with * at end or before /. */
         if (c == EOS)
            return (0);

         /* General case, use recursion. */
         while ((test = *string) != EOS) {
            if (!fnmatch1(pattern, string))
               return (0);
            ++string;
         }
         return (1);
         /* FALLTHROUGH */
      default:
         if (c != *string)
            return (1);
         string++;
         break;
      }
}

/*------------------------------------------------------------------*/

INT ss_file_find(char *path, char *pattern, char **plist)
/********************************************************************\

 Routine: ss_file_find
 
  Purpose: Return list of files matching 'pattern' from the 'path' location
  
   Input:
   char  *path             Name of a file in file system to check
   char  *pattern          pattern string (wildcard allowed)
   
    Output:
    char  **plist           pointer to the file list
    
     Function value:
     int                     Number of files matching request
     
      \********************************************************************/
{
#ifdef OS_UNIX
   DIR *dir_pointer;
   struct dirent *dp;
   int i;

   if ((dir_pointer = opendir(path)) == NULL)
      return 0;
   *plist = (char *) malloc(MAX_PATH_LENGTH);
   i = 0;
   for (dp = readdir(dir_pointer); dp != NULL; dp = readdir(dir_pointer)) {
      if (fnmatch1(pattern, dp->d_name) == 0) {
         *plist = (char *) realloc(*plist, (i + 1) * MAX_PATH_LENGTH);
         strncpy(*plist + (i * MAX_PATH_LENGTH), dp->d_name, strlen(dp->d_name));
         *(*plist + (i * MAX_PATH_LENGTH) + strlen(dp->d_name)) = '\0';
         i++;
         seekdir(dir_pointer, telldir(dir_pointer));
      }
   }
   closedir(dir_pointer);
   return i;
#endif

#ifdef OS_WINNT
   HANDLE pffile;
   LPWIN32_FIND_DATA lpfdata;
   char str[255];
   int i, first;

   strlcpy(str, path, sizeof(str));
   strlcat(str, "\\", sizeof(str));
   strlcat(str, pattern, sizeof(str));
   first = 1;
   i = 0;
   lpfdata = malloc(sizeof(WIN32_FIND_DATA));
   *plist = (char *) malloc(MAX_PATH_LENGTH);
   pffile = FindFirstFile(str, lpfdata);
   if (pffile == INVALID_HANDLE_VALUE)
      return 0;
   first = 0;
   *plist = (char *) realloc(*plist, (i + 1) * MAX_PATH_LENGTH);
   strncpy(*plist + (i * MAX_PATH_LENGTH), lpfdata->cFileName,
           strlen(lpfdata->cFileName));
   *(*plist + (i * MAX_PATH_LENGTH) + strlen(lpfdata->cFileName)) = '\0';
   i++;
   while (FindNextFile(pffile, lpfdata)) {
      *plist = (char *) realloc(*plist, (i + 1) * MAX_PATH_LENGTH);
      strncpy(*plist + (i * MAX_PATH_LENGTH), lpfdata->cFileName,
              strlen(lpfdata->cFileName));
      *(*plist + (i * MAX_PATH_LENGTH) + strlen(lpfdata->cFileName)) = '\0';
      i++;
   }
   free(lpfdata);
   return i;
#endif
}

/*------------------------------------------------------------------*/

int eli_compare(const void *e1, const void *e2)
{

   if (((EL_INDEX *) e1)->file_time < ((EL_INDEX *) e2)->file_time)
      return -1;
   if (((EL_INDEX *) e1)->file_time >= ((EL_INDEX *) e2)->file_time)
      return 1;
   return 0;
}

/*------------------------------------------------------------------*/

int el_build_index(LOGBOOK * lbs, BOOL rebuild)
/* scan all ??????a.log files and build an index table in eli[] */
{
   char *file_list, str[256], date[256], dir[256], file_name[MAX_PATH_LENGTH], *buffer,
       *p, *pn, in_reply_to[80];
   int index, n, length;
   int i, fh, len;
   time_t ltime;
   struct tm tms;

   if (rebuild) {
      free(lbs->el_index);
      free(lbs->n_el_index);
   }

   /* check if this logbook has same data dir as previous */
   for (i = 0; lb_list[i].name[0] && &lb_list[i] != lbs; i++)
      if (equal_ustring(lb_list[i].data_dir, lbs->data_dir))
         break;

   if (equal_ustring(lb_list[i].data_dir, lbs->data_dir)
       && &lb_list[i] != lbs) {
      if (verbose)
         printf("\n  Same index as logbook %s\n", lb_list[i].name);

      lbs->el_index = lb_list[i].el_index;
      lbs->n_el_index = lb_list[i].n_el_index;
      return EL_SUCCESS;
   }

   lbs->n_el_index = malloc(sizeof(int));
   *lbs->n_el_index = 0;
   lbs->el_index = malloc(0);

   /* get data directory */
   strcpy(dir, lbs->data_dir);

   file_list = NULL;
   n = ss_file_find(dir, "??????a.log", &file_list);
   if (n == 0) {
      if (file_list)
         free(file_list);
      file_list = NULL;

      n = ss_file_find(dir, "??????.log", &file_list);
      if (n > 0)
         return EL_UPGRADE;

      return EL_EMPTY;
   }

   /* go through all files */
   for (index = 0; index < n; index++) {
      strlcpy(file_name, dir, sizeof(file_name));
      strlcat(file_name, file_list + index * MAX_PATH_LENGTH, sizeof(file_name));

      fh = open(file_name, O_RDWR | O_BINARY, 0644);

      if (fh < 0) {
         sprintf(str, "Cannot open file \"%s\":", file_name);
         perror(str);
         return EL_FILE_ERROR;
      }

      /* read file into buffer */
      length = lseek(fh, 0, SEEK_END);

      if (length > 0) {
         buffer = malloc(length + 1);
         if (buffer == NULL) {
            printf("Not enough memory to allocate file buffer (%d bytes)\n", length);
            return EL_MEM_ERROR;
         }

         lseek(fh, 0, SEEK_SET);
         read(fh, buffer, length);
         buffer[length] = 0;
         close(fh);

         /* go through buffer */
         p = buffer;

         do {
            p = strstr(p, "$@MID@$:");

            if (p) {
               lbs->el_index =
                   realloc(lbs->el_index, sizeof(EL_INDEX) * (*lbs->n_el_index + 1));
               if (lbs->el_index == NULL) {
                  printf("Not enough memory to allocate entry index\n");
                  return EL_MEM_ERROR;
               }

               strcpy(str, file_list + index * MAX_PATH_LENGTH);
               strcpy(lbs->el_index[*lbs->n_el_index].file_name, str);

               el_decode(p, "Date: ", date);
               el_decode(p, "In reply to: ", in_reply_to);

               memset(&tms, 0, sizeof(struct tm));

               for (i = 0; i < 12; i++)
                  if (strncmp(date + 4, mname[i], 3) == 0)
                     break;
               tms.tm_mon = i;

               tms.tm_mday = atoi(date + 8);
               tms.tm_hour = atoi(date + 11);
               tms.tm_min = atoi(date + 14);
               tms.tm_sec = atoi(date + 17);
               tms.tm_year = atoi(date + 20) - 1900;
               tms.tm_isdst = -1;

               if (tms.tm_year < 90)
                  tms.tm_year += 100;
               ltime = mktime(&tms);

               lbs->el_index[*lbs->n_el_index].file_time = ltime;

               lbs->el_index[*lbs->n_el_index].message_id = atoi(p + 8);
               lbs->el_index[*lbs->n_el_index].offset = (int) p - (int) buffer;
               lbs->el_index[*lbs->n_el_index].in_reply_to = atoi(in_reply_to);

               pn = strstr(p + 8, "$@MID@$:");
               if (pn)
                  len = (int) pn - (int) p;
               else
                  len = strlen(p);

               MD5_checksum(p, len, lbs->el_index[*lbs->n_el_index].md5_digest);

               if (lbs->el_index[*lbs->n_el_index].message_id > 0) {
                  if (verbose) {
                     if (*lbs->n_el_index == 0)
                        printf("\n");

                     printf("  ID %3d in %s, ofs %5d, %s, MD5=",
                            lbs->el_index[*lbs->n_el_index].message_id,
                            str, lbs->el_index[*lbs->n_el_index].offset,
                            lbs->el_index[*lbs->n_el_index].
                            in_reply_to ? "reply" : "thead");

                     for (i = 0; i < 16; i++)
                        printf("%02X", lbs->el_index[*lbs->n_el_index].md5_digest[i]);
                     printf("\n");
                  }

                  /* valid ID */
                  (*lbs->n_el_index)++;
               }

               p += 8;
            }

         } while (p);

         free(buffer);
      }

   }

   free(file_list);

   /* sort entries according to date */
   qsort(lbs->el_index, *lbs->n_el_index, sizeof(EL_INDEX), eli_compare);

   if (verbose) {
      printf("After sort:\n");
      for (i = 0; i < *lbs->n_el_index; i++)
         printf("  ID %3d in %s, ofs %5d\n", lbs->el_index[i].message_id,
                lbs->el_index[i].file_name, lbs->el_index[i].offset);
   }

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int el_index_logbooks(BOOL reinit)
{
   char str[256], data_dir[256], logbook[256], cwd[256], *p;
   int i, j, n, status;

   if (reinit) {
      for (i = 0; lb_list[i].name[0]; i++) {
         if (lb_list[i].el_index != NULL) {
            free(lb_list[i].el_index);
            free(lb_list[i].n_el_index);

            /* check if other logbook uses same index */
            for (j = i + 1; lb_list[j].name[0]; j++) {
               /* mark that logbook already freed */
               if (lb_list[j].el_index == lb_list[i].el_index)
                  lb_list[j].el_index = NULL;
            }
         }
      }
      free(lb_list);
   }

   /* count logbooks */
   for (i = n = 0;; i++) {
      if (!enumgrp(i, str))
         break;

      if (!is_logbook(str))
         continue;

      n++;
   }

   lb_list = calloc(sizeof(LOGBOOK), n + 1);
   for (i = n = 0;; i++) {
      if (!enumgrp(i, logbook))
         break;

      if (!is_logbook(logbook))
         continue;

      /* check for duplicate name */
      for (j = 0; j < i; j++)
         if (equal_ustring(lb_list[j].name, logbook)) {
            printf("Error in configuration file: Duplicate logbook \"%s\"\n", logbook);
            return EL_DUPLICATE;
         }

      /* store logbook in list */
      strcpy(lb_list[n].name, logbook);
      strcpy(lb_list[n].name_enc, logbook);
      url_encode(lb_list[n].name_enc, sizeof(lb_list[n].name_enc));

      /* get data dir from configuration file (old method) */
      if (getcfg(logbook, "Data dir", str)) {
         if (str[0] == DIR_SEPARATOR || str[1] == ':')
            strlcpy(data_dir, str, sizeof(data_dir));
         else {
            strlcpy(data_dir, resource_dir, sizeof(data_dir));
            strlcat(data_dir, str, sizeof(data_dir));
         }
      } else {
         /* use logbook_dir + "Subdir" (new method) */
         strlcpy(data_dir, logbook_dir, sizeof(data_dir));
         if (data_dir[strlen(data_dir) - 1] != DIR_SEPARATOR)
            strlcat(data_dir, DIR_SEPARATOR_STR, sizeof(data_dir));

         if (getcfg(logbook, "Subdir", str)) {
            if (str[0] == DIR_SEPARATOR)
               strlcpy(data_dir, str, sizeof(data_dir));
            else
               strlcat(data_dir, str, sizeof(data_dir));
         } else
            strlcat(data_dir, logbook, sizeof(data_dir));       /* use logbook name as default */
      }

      if (data_dir[strlen(data_dir) - 1] != DIR_SEPARATOR)
         strlcat(data_dir, DIR_SEPARATOR_STR, sizeof(data_dir));

      /* create data directory if not existing */
      getcwd(cwd, sizeof(cwd));

      j = chdir(data_dir);
      if (j < 0) {
         p = data_dir;
         if (*p == DIR_SEPARATOR) {
            chdir(DIR_SEPARATOR_STR);
            p++;
         }
         if (p[1] == ':') {
            strcpy(str, p);
            if (str[2] == DIR_SEPARATOR)
               str[3] = 0;
            else
               str[2] = 0;

            chdir(str);
            p += strlen(str);
         }

         do {
            if (strchr(p, DIR_SEPARATOR)) {
               strlcpy(str, p, sizeof(str));
               *strchr(str, DIR_SEPARATOR) = 0;
               p = strchr(p, DIR_SEPARATOR) + 1;
            } else {
               strlcpy(str, p, sizeof(str));
               p = NULL;
            }

            j = chdir(str);
            if (j < 0) {

#ifdef OS_WINNT
               j = mkdir(str);
#else
               j = mkdir(str, 0755);
#endif

               if (j == 0)
                  printf("Created directory \"%s\"\n", str);
               else {
                  perror("el_index_logbooks");
                  printf("Cannot create directory \"%s\"\n", str);
               }

               chdir(str);
            }

         } while (p && *p);
      }

      chdir(cwd);
      strcpy(lb_list[n].data_dir, data_dir);
      lb_list[n].el_index = NULL;

      printf("Indexing logbook \"%s\" ... ", logbook);
      fflush(stdout);
      status = el_build_index(&lb_list[n], FALSE);
      printf("ok\n");

      if (status == EL_EMPTY)
         printf("Found empty logbook \"%s\"\n", logbook);
      else if (status == EL_UPGRADE) {
         printf("Please upgrade data files in \"%s\" with the elconv program.\n",
                data_dir);
         return EL_UPGRADE;
      } else if (status != EL_SUCCESS) {
         printf("Error generating index.\n");
         return status;
      }

      n++;
   }

   /* if top groups defined, set top group in logbook */
   if (exist_top_group()) {
      LBLIST phier;

      phier = get_logbook_hierarchy();
      for (i = 0; i < phier->n_members; i++)
         if (phier->member[i]->is_top)
            for (j = 0; lb_list[j].name[0]; j++)
               if (is_logbook_in_group(phier->member[i], lb_list[j].name))
                  strcpy(lb_list[j].top_group, phier->member[i]->name);


      free_logbook_hierarchy(phier);
   }


   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int el_search_message(LOGBOOK * lbs, int mode, int message_id, BOOL head_only)
/********************************************************************\

 Routine: el_search_message
 
  Purpose: Search for a specific message in a logbook
  
   Input:
   int   mode              Search mode, EL_FIRST, EL_LAST, EL_NEXT, EL_PREV
   int   message_id        Message id for EL_NEXT and EL_PREV
   
   Function value:
   int                     New message id
    
\********************************************************************/
{
   int i;

   if (lbs->n_el_index == 0)
      return 0;

   if (mode == EL_FIRST) {
      if (head_only) {
         for (i = 0; i < *lbs->n_el_index; i++)
            if (lbs->el_index[i].in_reply_to == 0)
               return lbs->el_index[i].message_id;

         return 0;
      }
      if (*lbs->n_el_index == 0)
         return 0;
      return lbs->el_index[0].message_id;
   }

   if (mode == EL_LAST) {
      if (head_only) {
         for (i = *lbs->n_el_index - 1; i >= 0; i--)
            if (lbs->el_index[i].in_reply_to == 0)
               return lbs->el_index[i].message_id;

         return 0;
      }
      if (*lbs->n_el_index == 0)
         return 0;
      return lbs->el_index[*lbs->n_el_index - 1].message_id;
   }

   if (mode == EL_NEXT) {
      for (i = 0; i < *lbs->n_el_index; i++)
         if (lbs->el_index[i].message_id == message_id)
            break;

      if (i == *lbs->n_el_index)
         return 0;              // message not found

      if (i == *lbs->n_el_index - 1)
         return 0;              // last message

      if (head_only) {
         for (i++; i < *lbs->n_el_index; i++)
            if (lbs->el_index[i].in_reply_to == 0)
               return lbs->el_index[i].message_id;

         return 0;
      }

      return lbs->el_index[i + 1].message_id;
   }

   if (mode == EL_PREV) {
      for (i = 0; i < *lbs->n_el_index; i++)
         if (lbs->el_index[i].message_id == message_id)
            break;

      if (i == *lbs->n_el_index)
         return 0;              // message not found

      if (i == 0)
         return 0;              // first message

      if (head_only) {
         for (i--; i >= 0; i--)
            if (lbs->el_index[i].in_reply_to == 0)
               return lbs->el_index[i].message_id;

         return 0;
      }

      return lbs->el_index[i - 1].message_id;
   }

   return 0;
}

/*------------------------------------------------------------------*/

INT el_retrieve(LOGBOOK * lbs,
                int message_id, char *date,
                char attr_list[MAX_N_ATTR][NAME_LENGTH],
                char attrib[MAX_N_ATTR][NAME_LENGTH], int n_attr,
                char *text, int *textsize, char *in_reply_to,
                char *reply_to, char attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH],
                char *encoding, char *locked_by)
/********************************************************************\

   Routine: el_retrieve

   Purpose: Retrieve an ELog entry by its message tab

   Input:
   LOGBOOK lbs             Logbook structure
   int    message_id       Message ID to retrieve
   int    *size            Size of text buffer

   Output:
   char   *tag             tag of retrieved message
   char   *date            Date/time of message recording
   char   attr_list        Names of attributes
   char   attrib           Values of attributes
   int    n_attr           Number of attributes
   char   *text            Message text
   char   *in_reply_to     Original message if this one is a reply
   char   *reply_to        Replies for current message
   char   *attachment[]    File attachments
   char   *encoding        Encoding of message
   char   *locked_by       User/Host if locked for editing
   int    *size            Actual message text size

   Function value:
   EL_SUCCESS              Successful completion
   EL_EMPTY                Logbook is empty
   EL_NO_MSG               Message doesn't exist
   EL_FILE_ERROR           Internal error

\********************************************************************/
{
   int i, index, size, fh;
   char str[NAME_LENGTH], file_name[256], *p;
   char message[TEXT_SIZE + 1000], attachment_all[64 * MAX_ATTACHMENTS];

   if (message_id == 0)
      /* open most recent message */
      message_id = el_search_message(lbs, EL_LAST, 0, FALSE);

   if (message_id == 0)
      return EL_EMPTY;

   for (index = 0; index < *lbs->n_el_index; index++)
      if (lbs->el_index[index].message_id == message_id)
         break;

   if (index == *lbs->n_el_index)
      return EL_NO_MSG;

   sprintf(file_name, "%s%s", lbs->data_dir, lbs->el_index[index].file_name);
   fh = open(file_name, O_RDWR | O_BINARY, 0644);
   if (fh < 0) {
      /* file might have been deleted, rebuild index */
      el_build_index(lbs, TRUE);
      return el_retrieve(lbs, message_id, date, attr_list, attrib, n_attr,
                         text, textsize, in_reply_to, reply_to, attachment, encoding,
                         locked_by);
   }

   lseek(fh, lbs->el_index[index].offset, SEEK_SET);
   i = read(fh, message, sizeof(message) - 1);
   if (i <= 0) {
      close(fh);
      return EL_FILE_ERROR;
   }

   message[i] = 0;
   close(fh);

   if (strncmp(message, "$@MID@$:", 8) != 0) {
      /* file might have been edited, rebuild index */
      el_build_index(lbs, TRUE);
      return el_retrieve(lbs, message_id, date, attr_list, attrib, n_attr,
                         text, textsize, in_reply_to, reply_to, attachment, encoding,
                         locked_by);
   }

   /* check for correct ID */
   if (atoi(message + 8) != message_id)
      return EL_FILE_ERROR;

   /* decode message size */
   p = strstr(message + 8, "$@MID@$:");
   if (p == NULL)
      size = strlen(message);
   else
      size = (int) p - (int) message;

   message[size] = 0;

   /* decode message */
   if (date)
      el_decode(message, "Date: ", date);
   if (reply_to)
      el_decode(message, "Reply to: ", reply_to);
   if (in_reply_to)
      el_decode(message, "In reply to: ", in_reply_to);

   if (n_attr == -1) {
      /* derive attribute names from message */
      for (i = 0;; i++) {
         el_enum_attr(message, i, attr_list[i], attrib[i]);
         if (!attr_list[i][0])
            break;
      }
      n_attr = i;

   } else {
      if (attrib)
         for (i = 0; i < n_attr; i++) {
            sprintf(str, "%s: ", attr_list[i]);
            el_decode(message, str, attrib[i]);
         }
   }

   el_decode(message, "Attachment: ", attachment_all);
   if (encoding)
      el_decode(message, "Encoding: ", encoding);

   if (attachment) {
      /* break apart attachements */
      for (i = 0; i < MAX_ATTACHMENTS; i++)
         if (attachment[i] != NULL)
            attachment[i][0] = 0;

      for (i = 0; i < MAX_ATTACHMENTS; i++) {
         if (attachment[i] != NULL) {
            if (i == 0)
               p = strtok(attachment_all, ",");
            else
               p = strtok(NULL, ",");

            if (p != NULL)
               strcpy(attachment[i], p);
            else
               break;
         }
      }
   }

   if (locked_by)
      el_decode(message, "Locked by: ", locked_by);

   p = strstr(message, "========================================\n");

   /* check for \n -> \r conversion (e.g. zipping/unzipping) */
   if (p == NULL)
      p = strstr(message, "========================================\r");

   if (text) {
      if (p != NULL) {
         p += 41;
         if ((int) strlen(p) >= *textsize) {
            strlcpy(text, p, *textsize);
            show_error
                ("Entry too long to display. Please increase TEXT_SIZE and recompile elogd.");
            return EL_FILE_ERROR;
         } else {
            strlcpy(text, p, *textsize);

            /* strip CR at end */
            if (text[strlen(text) - 1] == '\n') {
               text[strlen(text) - 1] = 0;
               if (text[strlen(text) - 1] == '\r')
                  text[strlen(text) - 1] = 0;
            }

            *textsize = strlen(text);
         }
      } else {
         text[0] = 0;
         *textsize = 0;
      }
   }

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int el_submit_attachment(LOGBOOK * lbs, char *afilename, char *buffer, int buffer_size,
                         char *full_name)
{
   char file_name[MAX_PATH_LENGTH], ext_file_name[MAX_PATH_LENGTH], str[MAX_PATH_LENGTH],
       *p;
   int fh;
   time_t now;
   struct tm tms;

   /* strip directory, add date and time to filename */
   strcpy(str, afilename);
   p = str;
   while (strchr(p, ':'))
      p = strchr(p, ':') + 1;
   while (strchr(p, '\\'))
      p = strchr(p, '\\') + 1;  /* NT */
   while (strchr(p, '/'))
      p = strchr(p, '/') + 1;   /* Unix */
   strcpy(file_name, p);

   /* assemble ELog filename */
   if (file_name[0]) {

      if (file_name[6] == '_' && file_name[13] == '_' && isdigit(file_name[0])
          && isdigit(file_name[1]))
         strcpy(ext_file_name, file_name);
      else {
         time(&now);
         memcpy(&tms, localtime(&now), sizeof(struct tm));

         sprintf(ext_file_name, "%02d%02d%02d_%02d%02d%02d_%s",
                 tms.tm_year % 100, tms.tm_mon + 1, tms.tm_mday, tms.tm_hour, tms.tm_min,
                 tms.tm_sec, file_name);
      }

      if (full_name)
         strcpy(full_name, ext_file_name);

      strcpy(str, lbs->data_dir);
      strcat(str, ext_file_name);

      /* save attachment */
      fh = open(str, O_CREAT | O_RDWR | O_BINARY, 0644);
      if (fh < 0) {
         sprintf(str, "Cannot write attachment file \"%s\"", str);
         show_error(str);
         return -1;
      } else {
         write(fh, buffer, buffer_size);
         close(fh);
      }
   }

   return 0;
}

/*------------------------------------------------------------------*/

void el_delete_attachment(LOGBOOK * lbs, char *file_name)
{
   char str[MAX_PATH_LENGTH];

   strlcpy(str, lbs->data_dir, sizeof(str));
   strlcat(str, file_name, sizeof(str));
   remove(str);
}

/*------------------------------------------------------------------*/

INT el_retrieve_attachment(LOGBOOK * lbs, int message_id, int n,
                           char name[MAX_PATH_LENGTH])
{
   int i, index, size, fh;
   char file_name[256], *p;
   char message[TEXT_SIZE + 1000], attachment_all[64 * MAX_ATTACHMENTS];

   if (message_id == 0)
      return EL_EMPTY;

   for (index = 0; index < *lbs->n_el_index; index++)
      if (lbs->el_index[index].message_id == message_id)
         break;

   if (index == *lbs->n_el_index)
      return EL_NO_MSG;

   sprintf(file_name, "%s%s", lbs->data_dir, lbs->el_index[index].file_name);
   fh = open(file_name, O_RDWR | O_BINARY, 0644);
   if (fh < 0) {
      /* file might have been deleted, rebuild index */
      el_build_index(lbs, TRUE);
      return el_retrieve_attachment(lbs, message_id, n, name);
   }

   lseek(fh, lbs->el_index[index].offset, SEEK_SET);
   i = read(fh, message, sizeof(message) - 1);
   if (i <= 0) {
      close(fh);
      return EL_FILE_ERROR;
   }

   message[i] = 0;
   close(fh);

   if (strncmp(message, "$@MID@$:", 8) != 0) {
      /* file might have been edited, rebuild index */
      el_build_index(lbs, TRUE);
      return el_retrieve_attachment(lbs, message_id, n, name);
   }

   /* check for correct ID */
   if (atoi(message + 8) != message_id)
      return EL_FILE_ERROR;

   /* decode message size */
   p = strstr(message + 8, "$@MID@$:");
   if (p == NULL)
      size = strlen(message);
   else
      size = (int) p - (int) message;

   message[size] = 0;

   el_decode(message, "Attachment: ", attachment_all);

   name[0] = 0;

   for (i = 0; i <= n; i++) {
      if (i == 0)
         p = strtok(attachment_all, ",");
      else
         p = strtok(NULL, ",");

      if (p == NULL)
         break;
   }

   if (p)
      strlcpy(name, p, MAX_PATH_LENGTH);

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int el_submit(LOGBOOK * lbs, int message_id, BOOL bedit,
              char *date,
              char attr_name[MAX_N_ATTR][NAME_LENGTH],
              char attr_value[MAX_N_ATTR][NAME_LENGTH],
              int n_attr, char *text,
              char *in_reply_to, char *reply_to,
              char *encoding, char afilename[MAX_ATTACHMENTS][256], BOOL mark_original,
              char *locked_by)
/********************************************************************\

   Routine: el_submit

   Purpose: Submit an ELog entry

   Input:
   LOGBOOK lbs             Logbook structure
   int    message_id       Message id 
   BOOL   bedit            TRUE for existing message, FALSE for new message
   char   *date            Message date
   char   attr_name[][]    Name of attributes
   char   attr_value[][]   Value of attributes
   int    n_attr           Number of attributes

   char   *text            Message text
   char   *in_reply_to     In reply to this message
   char   *reply_to        Replie(s) to this message
   char   *encoding        Text encoding, either HTML or plain

   char   *afilename[]     File name of attachments
   char   *tag             If given, edit existing message
   INT    *tag_size        Maximum size of tag
   BOOL   mark_original    Tag original message for replies
   char   *locked_by       User/Host which locked message for edit

   Function value:
   int                     New message ID

\********************************************************************/
{
   INT n, i, j, size, fh, index, tail_size, orig_size, delta, reply_id;
   struct tm tms;
   char file_name[256], dir[256], str[NAME_LENGTH];
   time_t now, ltime;
   char *message, *p, *buffer;
   char attachment_all[64 * MAX_ATTACHMENTS];

   message = malloc(TEXT_SIZE + 100);
   assert(message);

   /* generate new file name YYMMDD.log in data directory */
   strcpy(dir, lbs->data_dir);

   if (bedit) {
      /* edit existing message */
      for (index = 0; index < *lbs->n_el_index; index++)
         if (lbs->el_index[index].message_id == message_id)
            break;

      if (index == *lbs->n_el_index) {
         free(message);
         return -1;
      }

      sprintf(file_name, "%s%s", lbs->data_dir, lbs->el_index[index].file_name);
      fh = open(file_name, O_CREAT | O_RDWR | O_BINARY, 0644);
      if (fh < 0) {
         free(message);
         return -1;
      }

      lseek(fh, lbs->el_index[index].offset, SEEK_SET);
      i = read(fh, message, TEXT_SIZE+100);
      message[i] = 0;

      /* check for valid message */
      if (strncmp(message, "$@MID@$:", 8) != 0) {
         close(fh);
         free(message);

         /* file might have been edited, rebuild index */
         el_build_index(lbs, TRUE);
         return el_submit(lbs, message_id, bedit, date, attr_name, attr_value,
                          n_attr, text, in_reply_to, reply_to, encoding, afilename,
                          mark_original, locked_by);
      }

      /* check for correct ID */
      if (atoi(message + 8) != message_id) {
         close(fh);
         free(message);
         return -1;
      }

      /* decode message size */
      p = strstr(message + 8, "$@MID@$:");
      if (p == NULL)
         size = strlen(message);
      else
         size = (int) p - (int) message;

      message[size] = 0;

      if (equal_ustring(date, "<keep>"))
         el_decode(message, "Date: ", date);
      if (equal_ustring(reply_to, "<keep>"))
         el_decode(message, "Reply to: ", reply_to);
      if (equal_ustring(in_reply_to, "<keep>"))
         el_decode(message, "In reply to: ", in_reply_to);
      el_decode(message, "Attachment: ", attachment_all);

      /* buffer tail of logfile */
      lseek(fh, 0, SEEK_END);
      orig_size = size;
      tail_size = TELL(fh) - (lbs->el_index[index].offset + size);

      if (tail_size > 0) {
         buffer = malloc(tail_size);
         if (buffer == NULL) {
            close(fh);
            free(message);
            return -1;
         }

         lseek(fh, lbs->el_index[index].offset + size, SEEK_SET);
         n = read(fh, buffer, tail_size);
      }
      lseek(fh, lbs->el_index[index].offset, SEEK_SET);
   } else {
      /* create new message */
      if (!date[0]) {
         time(&now);
         strcpy(date, ctime(&now));
         date[24] = 0;
      }

      for (i = 0; i < 12; i++)
         if (strncmp(date + 4, mname[i], 3) == 0)
            break;

      memset(&tms, 0, sizeof(struct tm));
      tms.tm_mon = i;
      tms.tm_mday = atoi(date + 8);
      tms.tm_hour = atoi(date + 11);
      tms.tm_min = atoi(date + 14);
      tms.tm_sec = atoi(date + 17);
      tms.tm_year = atoi(date + 20) - 1900;

      if (tms.tm_year < 90)
         tms.tm_year += 100;
      ltime = mktime(&tms);

      if (date[8] == ' ')
         date[8] = '0';

      sprintf(file_name, "%c%c%02d%c%ca.log", date[22], date[23], i + 1, date[8],
              date[9]);

      sprintf(str, "%s%s", dir, file_name);
      fh = open(str, O_CREAT | O_RDWR | O_BINARY, 0644);
      if (fh < 0) {
         free(message);
         return -1;
      }

      lseek(fh, 0, SEEK_END);

      /* new message id is old plus one */
      if (message_id == 0) {
         message_id = 1;
         for (i = 0; i < *lbs->n_el_index; i++)
            if (lbs->el_index[i].message_id >= message_id)
               message_id = lbs->el_index[i].message_id + 1;
      }

      /* enter message in index */
      index = *lbs->n_el_index;

      (*lbs->n_el_index)++;
      lbs->el_index = realloc(lbs->el_index, sizeof(EL_INDEX) * (*lbs->n_el_index));
      lbs->el_index[index].message_id = message_id;
      strcpy(lbs->el_index[index].file_name, file_name);
      lbs->el_index[index].file_time = ltime;
      lbs->el_index[index].offset = TELL(fh);
      lbs->el_index[index].in_reply_to = atoi(in_reply_to);

      /* if index not ordered, sort it */
      i = *lbs->n_el_index;
      if (i > 1 && lbs->el_index[i - 1].file_time < lbs->el_index[i - 2].file_time) {
         qsort(lbs->el_index, i, sizeof(EL_INDEX), eli_compare);

         /* search message again, index could have been changed by sorting */
         for (index = 0; index < *lbs->n_el_index; index++)
            if (lbs->el_index[index].message_id == message_id)
               break;
      }

      /* if other logbook has same index, update pointers */
      for (i = 0; lb_list[i].name[0]; i++)
         if (&lb_list[i] != lbs && lb_list[i].n_el_index == lbs->n_el_index)
            lb_list[i].el_index = lbs->el_index;
   }

   /* compose message */

   sprintf(message, "$@MID@$: %d\n", message_id);
   sprintf(message + strlen(message), "Date: %s\n", date);

   if (reply_to[0])
      sprintf(message + strlen(message), "Reply to: %s\n", reply_to);

   if (in_reply_to[0])
      sprintf(message + strlen(message), "In reply to: %s\n", in_reply_to);

   for (i = 0; i < n_attr; i++)
      sprintf(message + strlen(message), "%s: %s\n", attr_name[i], attr_value[i]);

   sprintf(message + strlen(message), "Attachment: ");

   sprintf(message + strlen(message), afilename[0]);
   for (i = 1; i < MAX_ATTACHMENTS; i++)
      if (afilename[i][0])
         sprintf(message + strlen(message), ",%s", afilename[i]);
   sprintf(message + strlen(message), "\n");

   sprintf(message + strlen(message), "Encoding: %s\n", encoding);
   if (locked_by && locked_by[0])
      sprintf(message + strlen(message), "Locked by: %s\n", locked_by);

   sprintf(message + strlen(message), "========================================\n");
   strlcat(message, text, TEXT_SIZE+100);
   strlcat(message, "\n", TEXT_SIZE+100);

   write(fh, message, strlen(message));

   /* update MD5 checksum */
   MD5_checksum(message, strlen(message), lbs->el_index[index].md5_digest);

   if (bedit) {
      if (tail_size > 0) {
         n = write(fh, buffer, tail_size);
         free(buffer);

         /* correct offsets for remaining messages in same file */
         delta = strlen(message) - orig_size;

         for (i = 0; i < *lbs->n_el_index; i++)
            if (lbs->el_index[i].message_id == message_id)
               break;

         for (j = i + 1;
              j < *lbs->n_el_index
              && equal_ustring(lbs->el_index[i].file_name, lbs->el_index[j].file_name);
              j++)
            lbs->el_index[j].offset += delta;
      }

      /* truncate file here */
#ifdef _MSC_VER
      chsize(fh, TELL(fh));
#else
      ftruncate(fh, TELL(fh));
#endif
   }

   close(fh);

   /* if reply, mark original message */
   if (mark_original && in_reply_to[0] && !bedit && atoi(in_reply_to) > 0) {
      char date[80], attr[MAX_N_ATTR][NAME_LENGTH], enc[80], att[MAX_ATTACHMENTS][256],
          reply_to[MAX_REPLY_TO * 10], lock[256];

      reply_id = atoi(in_reply_to);

      /* retrieve original message */
      size = TEXT_SIZE+100;
      el_retrieve(lbs, reply_id, date, attr_list, attr, n_attr, message, &size,
                  in_reply_to, reply_to, att, enc, lock);

      if (reply_to[0])
         strcat(reply_to, ", ");
      sprintf(reply_to + strlen(reply_to), "%d", message_id);

      /* write modified message */
      el_submit(lbs, reply_id, TRUE, date, attr_list, attr, n_attr, message, in_reply_to,
                reply_to, enc, att, TRUE, lock);
   }

   free(message);
   return message_id;
}

/*------------------------------------------------------------------*/

void remove_reference(LOGBOOK * lbs, int message_id, int remove_id, BOOL reply_to_flag)
{
   char date[80], attr[MAX_N_ATTR][NAME_LENGTH], enc[80], in_reply_to[80],
       reply_to[MAX_REPLY_TO * 10], att[MAX_ATTACHMENTS][256], lock[256], 
       *p, *ps, *message;
   int size, status;

   /* retrieve original message */
   size = TEXT_SIZE+1000;
   message = malloc(size);
   status =
       el_retrieve(lbs, message_id, date, attr_list, attr, lbs->n_attr, message, &size,
                   in_reply_to, reply_to, att, enc, lock);
   if (status != EL_SUCCESS)
      return;

   if (reply_to_flag)
      p = reply_to;
   else
      p = in_reply_to;

   while (*p) {
      while (*p && (*p == ',' || *p == ' '))
         p++;

      ps = p;
      while (isdigit(*ps))
         ps++;

      while (*ps && (*ps == ',' || *ps == ' '))
         ps++;

      if (atoi(p) == remove_id)
         strcpy(p, ps);
      else
         while (isdigit(*p))
            p++;
   }

   /* write modified message */
   el_submit(lbs, message_id, TRUE, date, attr_list, attr, lbs->n_attr, message,
             in_reply_to, reply_to, enc, att, TRUE, lock);

   free(message);
}

/*------------------------------------------------------------------*/

INT el_delete_message(LOGBOOK * lbs, int message_id,
                      BOOL delete_attachments,
                      char attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH],
                      BOOL delete_bw_ref, BOOL delete_reply_to)
/********************************************************************\

   Routine: el_delete_message

   Purpose: Delete an ELog entry including attachments

   Input:
   LOGBOOK *lbs          Pointer to logbook structure
   int     message_id    Message ID
   BOOL    delete_attachments   Delete attachments if TRUE
   char    attachment    Used to return attachments (on move)
   BOOL    delete_bw_ref If true, delete backward references
   BOOL    delete_reply_to If true, delete replies to this message

   Output:
   <none>

   Function value:
   EL_SUCCESS              Successful completion

\********************************************************************/
{
   INT i, index, n, size, fh, tail_size, old_offset;
   char str[MAX_PATH_LENGTH], file_name[MAX_PATH_LENGTH], reply_to[MAX_REPLY_TO * 10],
       in_reply_to[256];
   char *buffer, *p;
   char *message, attachment_all[64 * MAX_ATTACHMENTS];

   for (index = 0; index < *lbs->n_el_index; index++)
      if (lbs->el_index[index].message_id == message_id)
         break;

   if (index == *lbs->n_el_index)
      return -1;

   sprintf(file_name, "%s%s", lbs->data_dir, lbs->el_index[index].file_name);
   fh = open(file_name, O_RDWR | O_BINARY, 0644);
   if (fh < 0)
      return EL_FILE_ERROR;

   message = malloc(TEXT_SIZE + 1000);

   lseek(fh, lbs->el_index[index].offset, SEEK_SET);
   i = read(fh, message, TEXT_SIZE + 1000 - 1);
   if (i <= 0) {
      free(message);
      close(fh);
      return EL_FILE_ERROR;
   }

   if (_logging_level > 1)
      logf(lbs, "DELETE entry #%d", message_id);

   message[i] = 0;

   if (strncmp(message, "$@MID@$:", 8) != 0) {
      close(fh);
      free(message);

      /* file might have been edited, rebuild index */
      el_build_index(lbs, TRUE);
      return el_delete_message(lbs, message_id, delete_attachments, attachment,
                               delete_bw_ref, delete_reply_to);
   }

   /* check for correct ID */
   if (atoi(message + 8) != message_id) {
      close(fh);
      free(message);
      return EL_FILE_ERROR;
   }

   /* decode message size */
   p = strstr(message + 8, "$@MID@$:");
   if (p == NULL)
      size = strlen(message);
   else
      size = (int) p - (int) message;

   message[size] = 0;

   /* delete attachments */
   el_decode(message, "Attachment: ", attachment_all);

   for (i = 0; i < MAX_ATTACHMENTS; i++) {
      if (i == 0)
         p = strtok(attachment_all, ",");
      else
         p = strtok(NULL, ",");

      if (attachment != NULL) {
         if (attachment[i][0] && p) {
            /* delete old attachment if new one exists */
            strlcpy(str, lbs->data_dir, sizeof(str));
            strlcat(str, p, sizeof(str));
            remove(str);
         }

         /* return old attachment if no new one */
         if (!attachment[i][0] && p)
            strcpy(attachment[i], p);
      }

      if (delete_attachments && p) {
         strlcpy(str, lbs->data_dir, sizeof(str));
         strlcat(str, p, sizeof(str));
         remove(str);
      }
   }

   /* decode references */
   el_decode(message, "Reply to: ", reply_to);
   el_decode(message, "In reply to: ", in_reply_to);

   /* buffer tail of logfile */
   lseek(fh, 0, SEEK_END);
   tail_size = TELL(fh) - (lbs->el_index[index].offset + size);

   if (tail_size > 0) {
      buffer = malloc(tail_size);
      if (buffer == NULL) {
         free(message);
         close(fh);
         return EL_FILE_ERROR;
      }

      lseek(fh, lbs->el_index[index].offset + size, SEEK_SET);
      n = read(fh, buffer, tail_size);
   }
   lseek(fh, lbs->el_index[index].offset, SEEK_SET);

   if (tail_size > 0) {
      n = write(fh, buffer, tail_size);
      free(buffer);
   }

   /* truncate file here */
#ifdef OS_WINNT
   chsize(fh, TELL(fh));
#else
   ftruncate(fh, TELL(fh));
#endif

   /* if file length gets zero, delete file */
   tail_size = lseek(fh, 0, SEEK_END);
   close(fh);
   free(message);

   if (tail_size == 0)
      remove(file_name);

   /* remove message from index */
   strcpy(str, lbs->el_index[index].file_name);
   old_offset = lbs->el_index[index].offset;
   for (i = index; i < *lbs->n_el_index - 1; i++) {
      memcpy(&lbs->el_index[i], &lbs->el_index[i + 1], sizeof(EL_INDEX));
   }
   (*lbs->n_el_index)--;
   lbs->el_index = realloc(lbs->el_index, sizeof(EL_INDEX) * (*lbs->n_el_index));

   /* correct all offsets after deleted message */
   for (i = 0; i < *lbs->n_el_index; i++)
      if (equal_ustring(lbs->el_index[i].file_name, str) &&
          lbs->el_index[i].offset > old_offset)
         lbs->el_index[i].offset -= size;

   /* if other logbook has same index, update pointers */
   for (i = 0; lb_list[i].name[0]; i++)
      if (&lb_list[i] != lbs && lb_list[i].n_el_index == lbs->n_el_index)
         lb_list[i].el_index = lbs->el_index;

   /* delete also replies to this message */
   if (delete_reply_to && reply_to[0]) {
      p = reply_to;
      if (isdigit(*p))
         do {
            if (atoi(p))
               el_delete_message(lbs, atoi(p), TRUE, NULL, FALSE, TRUE);

            while (*p && isdigit(*p))
               p++;
            while (*p && (*p == ',' || *p == ' '))
               p++;
         } while (*p);
   }

   /* delete backward references */
   if (in_reply_to[0] && delete_bw_ref) {
      p = in_reply_to;
      do {
         if (atoi(p))
            remove_reference(lbs, atoi(p), message_id, TRUE);

         while (*p && isdigit(*p))
            p++;
         while (*p && (*p == ',' || *p == ' '))
            p++;
      } while (*p);
   }

   /* execute shell if requested */
   if (getcfg(lbs->name, "Execute delete", str))
      execute_shell(lbs, message_id, NULL, str);

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int el_correct_links(LOGBOOK * lbs, int old_id, int new_id)
/* If a message gets resubmitted, the links to that message are wrong.
This routine corrects that. */
{
   int i, i1, n, n1, size;
   char date[80], attrib[MAX_N_ATTR][NAME_LENGTH], text[TEXT_SIZE],
       in_reply_to[80], reply_to[MAX_REPLY_TO * 10], encoding[80], locked_by[256];
   char list[MAX_N_ATTR][NAME_LENGTH], list1[MAX_N_ATTR][NAME_LENGTH];
   char att_file[MAX_ATTACHMENTS][256];

   el_retrieve(lbs, new_id, date, attr_list, attrib, lbs->n_attr, NULL, 0, in_reply_to,
               reply_to, att_file, encoding, locked_by);

   /* go through in_reply_to list */
   n = strbreak(in_reply_to, list, MAX_N_ATTR);
   for (i = 0; i < n; i++) {
      size = sizeof(text);
      el_retrieve(lbs, atoi(list[i]), date, attr_list, attrib, lbs->n_attr,
                  text, &size, in_reply_to, reply_to, att_file, encoding, locked_by);

      n1 = strbreak(reply_to, list1, MAX_N_ATTR);
      reply_to[0] = 0;
      for (i1 = 0; i1 < n1; i1++) {
         /* replace old ID by new ID */
         if (atoi(list1[i1]) == old_id)
            sprintf(reply_to + strlen(reply_to), "%d", new_id);
         else
            strcat(reply_to, list1[i1]);

         if (i1 < n1 - 1)
            strcat(reply_to, ", ");
      }

      el_submit(lbs, atoi(list[i]), TRUE, date, attr_list, attrib, lbs->n_attr,
                text, in_reply_to, reply_to, encoding, att_file, TRUE, locked_by);
   }

   el_retrieve(lbs, new_id, date, attr_list, attrib, lbs->n_attr, NULL, 0, in_reply_to,
               reply_to, att_file, encoding, locked_by);

   /* go through reply_to list */
   n = strbreak(reply_to, list, MAX_N_ATTR);
   for (i = 0; i < n; i++) {
      size = sizeof(text);
      el_retrieve(lbs, atoi(list[i]), date, attr_list, attrib, lbs->n_attr,
                  text, &size, in_reply_to, reply_to, att_file, encoding, locked_by);

      n1 = strbreak(in_reply_to, list1, MAX_N_ATTR);
      in_reply_to[0] = 0;
      for (i1 = 0; i1 < n1; i1++) {
         /* replace old ID by new ID */
         if (atoi(list1[i1]) == old_id)
            sprintf(in_reply_to + strlen(in_reply_to), "%d", new_id);
         else
            strcat(in_reply_to, list1[i1]);

         if (i1 < n1 - 1)
            strcat(in_reply_to, ", ");
      }

      el_submit(lbs, atoi(list[i]), TRUE, date, attr_list, attrib, lbs->n_attr,
                text, in_reply_to, reply_to, encoding, att_file, TRUE, locked_by);
   }

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int el_move_message_thread(LOGBOOK * lbs, int message_id)
{
   int i, n, size, new_id;
   char date[80], attrib[MAX_N_ATTR][NAME_LENGTH], *text,
       in_reply_to[80], reply_to[MAX_REPLY_TO * 10], encoding[80], locked_by[256];
   char list[MAX_N_ATTR][NAME_LENGTH], str[256];
   char att_file[MAX_ATTACHMENTS][256];

   /* retrieve message */
   text = malloc(TEXT_SIZE);
   size = TEXT_SIZE;
   el_retrieve(lbs, message_id, date, attr_list, attrib, lbs->n_attr,
               text, &size, in_reply_to, reply_to, att_file, encoding, locked_by);

   /* submit as new message */
   date[0] = 0;
   new_id = el_submit(lbs, 0, FALSE, date, attr_list, attrib, lbs->n_attr, text,
                      in_reply_to, reply_to, encoding, att_file, FALSE, locked_by);

   free(text);

   /* correct links */
   el_correct_links(lbs, message_id, new_id);

   /* delete original message */
   el_delete_message(lbs, message_id, FALSE, NULL, FALSE, FALSE);

   /* move all replies recursively */
   if (getcfg(lbs->name, "Resubmit replies", str) && atoi(str) == 1) {
      if (reply_to[0]) {
         n = strbreak(reply_to, list, MAX_N_ATTR);
         for (i = 0; i < n; i++)
            el_move_message_thread(lbs, atoi(list[i]));
      }
   }

   return new_id;
}

/*------------------------------------------------------------------*/

int el_move_message(LOGBOOK * lbs, int old_id, int new_id)
{
   int status, size;
   char date[80], attrib[MAX_N_ATTR][NAME_LENGTH], *text, in_reply_to[80],
       reply_to[MAX_REPLY_TO * 10], encoding[80], locked_by[256],
       att_file[MAX_ATTACHMENTS][256];

   /* retrieve message */
   text = malloc(TEXT_SIZE);
   size = TEXT_SIZE;
   status = el_retrieve(lbs, old_id, date, attr_list, attrib, lbs->n_attr,
                        text, &size, in_reply_to, reply_to, att_file, encoding,
                        locked_by);
   if (status != EL_SUCCESS)
      return 0;

   /* submit as new message */
   status = el_submit(lbs, new_id, FALSE, date, attr_list, attrib, lbs->n_attr, text,
                      in_reply_to, reply_to, encoding, att_file, FALSE, locked_by);

   free(text);

   if (status != new_id)
      return 0;

   /* correct links */
   el_correct_links(lbs, old_id, new_id);

   /* delete original message */
   el_delete_message(lbs, old_id, FALSE, NULL, FALSE, FALSE);

   return 1;
}

/*------------------------------------------------------------------*/

int el_lock_message(LOGBOOK * lbs, int message_id, char *user)
/* lock message for editing */
{
   int size;
   char date[80], attrib[MAX_N_ATTR][NAME_LENGTH], text[TEXT_SIZE],
       in_reply_to[80], reply_to[MAX_REPLY_TO * 10], encoding[80], locked_by[256];
   char att_file[MAX_ATTACHMENTS][256];

   /* retrieve message */
   size = sizeof(text);
   el_retrieve(lbs, message_id, date, attr_list, attrib, lbs->n_attr,
               text, &size, in_reply_to, reply_to, att_file, encoding, locked_by);

   /* submit message, unlocked if user==NULL */
   el_submit(lbs, message_id, TRUE, date, attr_list, attrib, lbs->n_attr, text,
             in_reply_to, reply_to, encoding, att_file, FALSE, user);

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

void logf(LOGBOOK * lbs, const char *format, ...)
{
   char file_name[2000];
   va_list argptr;
   char str[10000];
   FILE *f;
   time_t now;
   char buf[1000];

   if (lbs == NULL) {
      if (!getcfg("global", "logfile", str))
         return;
   } else if (!getcfg(lbs->name, "logfile", str))
      return;

   if (str[0] == DIR_SEPARATOR || str[1] == ':')
      strcpy(file_name, str);
   else {
      strlcpy(file_name, resource_dir, sizeof(file_name));
      strlcat(file_name, str, sizeof(file_name));
   }

   va_start(argptr, format);
   vsprintf(str, (char *) format, argptr);
   va_end(argptr);

   f = fopen(file_name, "a");
   if (!f)
      return;

   now = time(0);
   strftime(buf, sizeof(buf), "%d-%b-%Y %H:%M:%S", localtime(&now));
   strcat(buf, " ");

   if (*getparam("unm") && rem_host[0])
      sprintf(buf + strlen(buf), "[%s@%s] ", getparam("unm"), rem_host);
   else if (rem_host[0])
      sprintf(buf + strlen(buf), "[%s] ", rem_host);

   if (lbs)
      sprintf(buf + strlen(buf), "{%s} ", lbs->name);

   strlcat(buf, str, sizeof(buf));
   if (buf[strlen(buf) - 1] != '\n')
      strlcat(buf, "\n", sizeof(buf));

   fprintf(f, buf);

   fclose(f);
}

/*------------------------------------------------------------------*/

void rsputs(const char *str)
{
   if (strlen_retbuf + (int) strlen(str) > return_buffer_size) {
      return_buffer = realloc(return_buffer, return_buffer_size + 100000);
      memset(return_buffer + return_buffer_size, 0, 100000);
      return_buffer_size += 100000;
   }

   strcpy(return_buffer + strlen_retbuf, str);
   strlen_retbuf += strlen(str);
}

/*------------------------------------------------------------------*/

char *list[] = { "http://", "https://", "ftp://", "mailto:", "elog:", "file://", "" };

void rsputs2(const char *str)
{
   int i, j, k, l, m, n;
   char *p, *pd, link[1000], link_text[1000], tmp[256];

   if (strlen_retbuf + (int) strlen(str) > return_buffer_size) {
      return_buffer = realloc(return_buffer, return_buffer_size + 100000);
      memset(return_buffer + return_buffer_size, 0, 100000);
      return_buffer_size += 100000;
   }

   j = strlen_retbuf;
   for (i = 0; i < (int) strlen(str); i++) {
      for (l = 0; list[l][0]; l++) {
         if (strncmp(str + i, list[l], strlen(list[l])) == 0) {
            p = (char *) (str + i + strlen(list[l]));
            i += strlen(list[l]);
            for (k = 0; *p && strcspn(p, " ,\t\n\r({[)}]"); k++, i++)
               link[k] = *p++;
            link[k] = 0;
            i--;

            /* check if link contains coloring */
            p = strchr(link, '\001');
            if (p != NULL) {
               strlcpy(link_text, link, sizeof(link_text));

               /* skip everything between '<' and '>' */
               pd = p;
               while (*pd && *pd != '\002')
                  *p = *pd++;

               strcpy(p, pd + 1);

               /* skip '</B>' */
               p = strchr(link, '\001');
               if (p != NULL) {
                  pd = p;

                  while (*pd && *pd != '\002')
                     *p = *pd++;

                  strcpy(p, pd + 1);
               }

               /* correct link text */
               for (n = 0; n < (int) strlen(link_text); n++) {
                  switch (link_text[n]) {
                     /* the translation for the search highliting */
                  case '\001':
                     link_text[n] = '<';
                     break;
                  case '\002':
                     link_text[n] = '>';
                     break;
                  case '\003':
                     link_text[n] = '\"';
                     break;
                  case '\004':
                     link_text[n] = ' ';
                     break;
                  }
               }

            } else
               strlcpy(link_text, link, sizeof(link_text));

            if (strcmp(list[l], "elog:") == 0) {
               strlcpy(tmp, link, sizeof(tmp));
               if (strchr(tmp, '/'))
                  *strchr(tmp, '/') = 0;

               for (m = 0; m < (int) strlen(tmp); m++)
                  if (!isdigit(tmp[m]))
                     break;

               if (m < (int) strlen(tmp))
                  /* if link contains reference to other logbook, add ".." in front */
                  sprintf(return_buffer + j, "<a href=\"../%s\">elog:%s</a>", link,
                          link_text);
               else if (link[0] == '/')
                  sprintf(return_buffer + j, "<a href=\"%d%s\">elog:%s</a>",
                          _current_message_id, link, link_text);
               else
                  sprintf(return_buffer + j, "<a href=\"%s\">elog:%s</a>", link,
                          link_text);
            } else {
               sprintf(return_buffer + j, "<a href=\"%s%s\">%s", list[l], link, list[l]);
               j += strlen(return_buffer + j);
               strlen_retbuf = j;

               /* link_text can contain special characters */
               rsputs2(link_text);
               j = strlen_retbuf;
               sprintf(return_buffer + j, "</a>");
            }

            j += strlen(return_buffer + j);
            break;
         }
      }

      if (!list[l][0]) {
         if (strncmp(str + i, "<br>", 4) == 0) {
            strcpy(return_buffer + j, "<br>");
            j += 4;
            i += 3;
         } else
            switch (str[i]) {
            case '<':
               strcat(return_buffer, "&lt;");
               j += 4;
               break;
            case '>':
               strcat(return_buffer, "&gt;");
               j += 4;
               break;

               /* the translation for the search highliting */
            case '\001':
               strcat(return_buffer, "<");
               j++;
               break;
            case '\002':
               strcat(return_buffer, ">");
               j++;
               break;
            case '\003':
               strcat(return_buffer, "\"");
               j++;
               break;
            case '\004':
               strcat(return_buffer, " ");
               j++;
               break;

            default:
               return_buffer[j++] = str[i];
            }
      }
   }

   return_buffer[j] = 0;
   strlen_retbuf = j;
}

/*------------------------------------------------------------------*/

void rsprintf(const char *format, ...)
{
   va_list argptr;
   char str[10000];

   va_start(argptr, format);
   vsprintf(str, (char *) format, argptr);
   va_end(argptr);

   if (strlen_retbuf + (int) strlen(str) > return_buffer_size) {
      return_buffer = realloc(return_buffer, return_buffer_size + 100000);
      memset(return_buffer + return_buffer_size, 0, 100000);
      return_buffer_size += 100000;
   }

   strcpy(return_buffer + strlen_retbuf, str);

   strlen_retbuf += strlen(str);
}

/*------------------------------------------------------------------*/

void flush_return_buffer()
{
   send(_sock, return_buffer, strlen_retbuf, 0);
   memset(return_buffer, 0, return_buffer_size);
   strlen_retbuf = 0;
}

/*------------------------------------------------------------------*/

/* Parameter handling functions similar to setenv/getenv */

void initparam()
{
   memset(_param, 0, sizeof(_param));
   memset(_value, 0, sizeof(_value));
   _mtext[0] = 0;
   _cmdline[0] = 0;
}

int setparam(char *param, char *value)
{
   int i;
   char str[10000];

   if (equal_ustring(param, "text")) {
      if (strlen(value) >= TEXT_SIZE) {
         sprintf(str,
                 "Error: Entry text too big (%d bytes). Please increase TEXT_SIZE and recompile elogd\n",
                 strlen(value));
         show_error(str);
         return 0;
      }

      strlcpy(_mtext, value, TEXT_SIZE);
      return 1;
   }

   if (equal_ustring(param, "cmdline")) {
      if (strlen(value) >= CMD_SIZE) {
         sprintf(str,
                 "Error: Command line too big (%d bytes). Please increase CMD_SIZE and recompile elogd\n",
                 strlen(value));
         show_error(str);
         return 0;
      }

      strlcpy(_cmdline, value, CMD_SIZE);
      return 1;
   }

   /* paremeters can be superseeded */
   for (i = 0; i < MAX_PARAM; i++)
      if (_param[i][0] == 0 || equal_ustring(param, _param[i]))
         break;

   if (i < MAX_PARAM) {
      if (strlen(param) >= NAME_LENGTH) {
         sprintf(str, "Error: Parameter name too big (%d bytes).\n", strlen(param));
         show_error(str);
         return 0;
      }

      strlcpy(_param[i], param, NAME_LENGTH);

      if (strlen(value) >= NAME_LENGTH) {
         sprintf(str,
                 "Error: Parameter value for parameter <b>%s</b> too big (%d bytes). Please increase NAME_LENGTH and recompile elogd\n",
                 param, strlen(value));
         show_error(str);
         return 0;
      }

      strlcpy(_value[i], value, NAME_LENGTH);
   } else {
      printf("Error: parameter array too small\n");
   }

   return 1;
}

char *getparam(char *param)
{
   int i;

   if (equal_ustring(param, "text"))
      return _mtext;

   if (equal_ustring(param, "cmdline"))
      return _cmdline;

   for (i = 0; i < MAX_PARAM && _param[i][0]; i++)
      if (equal_ustring(param, _param[i]))
         break;

   if (i < MAX_PARAM)
      return _value[i];

   return NULL;
}

BOOL enumparam(int n, char *param, char *value)
{
   param[0] = value[0] = 0;

   if (n >= MAX_PARAM)
      return FALSE;

   if (_param[n][0] == 0)
      return FALSE;

   strcpy(param, _param[n]);
   strcpy(value, _value[n]);

   return TRUE;
}

BOOL isparam(char *param)
{
   int i;

   for (i = 0; i < MAX_PARAM && _param[i][0]; i++)
      if (equal_ustring(param, _param[i]))
         break;

   if (i < MAX_PARAM && _param[i][0])
      return TRUE;

   return FALSE;
}

void unsetparam(char *param)
{
   int i;

   for (i = 0; i < MAX_PARAM; i++)
      if (equal_ustring(param, _param[i]))
         break;

   if (i < MAX_PARAM) {
      for (; i < MAX_PARAM - 1; i++) {
         strlcpy(_param[i], _param[i + 1], NAME_LENGTH);
         strlcpy(_value[i], _value[i + 1], NAME_LENGTH);
      }
      _param[MAX_PARAM - 1][0] = 0;
      _value[MAX_PARAM - 1][0] = 0;
   }
}

/*------------------------------------------------------------------*/

void extract_path(char *str)
{
   char *p, str2[256];

   if (strstr(str, "http://")) {
      p = str + 7;
      while (*p && *p != '/')
         p++;
      if (*p == '/')
         p++;

      strcpy(str2, p);
      strcpy(str, str2);
      if (str[strlen(str) - 1] == '/')
         str[strlen(str) - 1] = 0;
   }
}

/*------------------------------------------------------------------*/

void set_location(LOGBOOK * lbs, char *rel_path)
{
   char str[NAME_LENGTH];

   if (strncmp(rel_path, "http://", 7) == 0) {
      rsputs("Location: ");
      rsputs(rel_path);
   } else {
      if (lbs)
         getcfg(lbs->name, "URL", str);
      else
         getcfg("global", "URL", str);

      if (str[0]) {
         /* absolute path */
         if (str[strlen(str) - 1] != '/')
            strcat(str, "/");

         rsputs("Location: ");
         rsputs(str);

         /* add top group if existing and not logbook */
         if (!lbs && getcfg_topgroup()) {
            rsputs(getcfg_topgroup());
            rsputs("/");
         }

         if (strncmp(rel_path, "../", 3) == 0)
            rsputs(rel_path + 3);
         else if (strcmp(rel_path, ".") == 0) {
            if (lbs)
               rsputs(lbs->name_enc);
         } else if (rel_path[0] == '/')
            rsputs(rel_path + 1);
         else {
            if (lbs) {
               rsputs(lbs->name_enc);
               rsputs("/");
               rsputs(rel_path);
            } else
               rsputs(rel_path);
         }
      } else {
         /* relative path */
         rsputs("Location: ");

         if (rel_path[0] == 0)
            rsputs(".");        /* empty location forbidden for konqueror */
         else
            rsputs(rel_path);
      }
   }

   rsprintf("\r\n\r\n<html>redir</html>\r\n");
}

/*------------------------------------------------------------------*/

void set_redir(LOGBOOK * lbs, char *redir)
{
   char str[NAME_LENGTH];

   str[0] = 0;

   /* prepare relative path */
   if (redir[0])
      strcpy(str, redir);
   else {
      if (lbs)
         sprintf(str, "../%s/", lbs->name_enc);
      else if (getcfg_topgroup())
         sprintf(str, ".");
   }

   set_location(lbs, str);
}

/*------------------------------------------------------------------*/

void set_cookie(LOGBOOK * lbs, char *name, char *value, BOOL global, char *expiration)
{
   char lb_name[256], str[NAME_LENGTH];
   double exp;
   time_t now;
   struct tm *gmt;

   if (lbs)
      strcpy(lb_name, lbs->name);
   else
      strcpy(lb_name, "global");

   rsprintf("Set-Cookie: %s=%s;", name, value);

   /* add path */
   if (global) {
      /* path for all logbooks */
      if (getcfg(lb_name, "URL", str)) {
         extract_path(str);
         url_encode(str, sizeof(str));
         rsprintf(" path=/%s;", str);
      } else
         rsprintf(" path=/;");
   } else {
      /* bug in lynx: path has to be absolute */
      if (strstr(browser, "Lynx/") != NULL) {
         /* path for individual logbook */
         if (getcfg(lb_name, "URL", str)) {
            extract_path(str);
            url_encode(str, sizeof(str));
            if (str[0])
               rsprintf(" path=/%s/%s;", str, lbs->name_enc);
            else
               rsprintf(" path=/%s;", lbs->name_enc);
         } else
            rsprintf(" path=/%s;", lbs->name_enc);
      }
   }

   exp = atof(expiration);

   /* to clear a cookie, set expiration date to yesterday */
   if (value[0] == 0)
      exp = -24;

   /* add expriation date */
   if (exp != 0) {
      time(&now);
      now += (int) (3600 * exp);
      gmt = gmtime(&now);
      strftime(str, sizeof(str), "%A, %d-%b-%y %H:%M:%S GMT", gmt);

      rsprintf(" expires=%s;", str);
   }

   rsprintf("\r\n");
}

/*------------------------------------------------------------------*/

void redirect(LOGBOOK * lbs, char *rel_path)
{
   /* redirect */
   rsprintf("HTTP/1.1 302 Found\r\n");
   rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
   if (use_keepalive) {
      rsprintf("Connection: Keep-Alive\r\n");
      rsprintf("Keep-Alive: timeout=60, max=10\r\n");
   }

   set_location(lbs, rel_path);
}

/*------------------------------------------------------------------*/

int strbreak(char *str, char list[][NAME_LENGTH], int size)
/* break comma-separated list into char array, stripping leading
and trailing blanks */
{
   int i;
   char *p;

   memset(list, 0, size * NAME_LENGTH);
   p = str;
   if (!p || !*p)
      return 0;

   while (*p == ' ')
      p++;

   for (i = 0; *p && i < size; i++) {
      if (*p == '"') {
         p++;

         strlcpy(list[i], p, NAME_LENGTH);

         if (strchr(list[i], '"'))
            *strchr(list[i], '"') = 0;

         p += strlen(list[i]) + 1;
         while (*p == ' ' || *p == ',')
            p++;
      } else {
         strlcpy(list[i], p, NAME_LENGTH);

         if (strchr(list[i], ','))
            *strchr(list[i], ',') = 0;

         p += strlen(list[i]);
         while (*p == ' ' || *p == ',')
            p++;
      }

      while (list[i][strlen(list[i]) - 1] == ' ')
         list[i][strlen(list[i]) - 1] = 0;

      if (!*p)
         break;
   }

   if (i == size)
      return size;

   return i + 1;
}

/*------------------------------------------------------------------*/

int scan_attributes(char *logbook, char *condition)
/* scan configuration file for attributes and fill attr_list, attr_options
and attr_flags arrays */
{
   char list[10000], str[NAME_LENGTH], tmp_list[MAX_N_ATTR][NAME_LENGTH];
   int i, j, n, m;

   if (getcfg_cond(logbook, condition, "Attributes", list)) {
      /* reset attribute flags */
      memset(attr_flags, 0, sizeof(attr_flags));

      /* get attribute list */
      memset(attr_list, 0, sizeof(attr_list));
      n = strbreak(list, attr_list, MAX_N_ATTR);

      /* get options lists for attributes */
      memset(attr_options, 0, sizeof(attr_options));
      for (i = 0; i < n; i++) {
         sprintf(str, "Options %s", attr_list[i]);
         if (getcfg_cond(logbook, condition, str, list))
            strbreak(list, attr_options[i], MAX_N_LIST);

         sprintf(str, "MOptions %s", attr_list[i]);
         if (getcfg_cond(logbook, condition, str, list)) {
            strbreak(list, attr_options[i], MAX_N_LIST);
            attr_flags[i] |= AF_MULTI;
         }

         sprintf(str, "ROptions %s", attr_list[i]);
         if (getcfg_cond(logbook, condition, str, list)) {
            strbreak(list, attr_options[i], MAX_N_LIST);
            attr_flags[i] |= AF_RADIO;
         }

         sprintf(str, "IOptions %s", attr_list[i]);
         if (getcfg_cond(logbook, condition, str, list)) {
            strbreak(list, attr_options[i], MAX_N_LIST);
            attr_flags[i] |= AF_ICON;
         }
      }

      /* check if attribute required */
      getcfg_cond(logbook, condition, "Required Attributes", list);
      m = strbreak(list, tmp_list, MAX_N_ATTR);
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++)
            if (equal_ustring(attr_list[j], tmp_list[i]))
               attr_flags[j] |= AF_REQUIRED;
      }

      /* check if locked attribute */
      getcfg_cond(logbook, condition, "Locked Attributes", list);
      m = strbreak(list, tmp_list, MAX_N_ATTR);
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++)
            if (equal_ustring(attr_list[j], tmp_list[i]))
               attr_flags[j] |= AF_LOCKED;
      }

      /* check if fixed attribute for Edit */
      getcfg_cond(logbook, condition, "Fixed Attributes Edit", list);
      m = strbreak(list, tmp_list, MAX_N_ATTR);
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++)
            if (equal_ustring(attr_list[j], tmp_list[i]))
               attr_flags[j] |= AF_FIXED_EDIT;
      }

      /* check if fixed attribute for Reply */
      getcfg_cond(logbook, condition, "Fixed Attributes Reply", list);
      m = strbreak(list, tmp_list, MAX_N_ATTR);
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++)
            if (equal_ustring(attr_list[j], tmp_list[i]))
               attr_flags[j] |= AF_FIXED_REPLY;
      }

      /* check for extendable options */
      getcfg_cond(logbook, condition, "Extendable Options", list);
      m = strbreak(list, tmp_list, MAX_N_ATTR);
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++)
            if (equal_ustring(attr_list[j], tmp_list[i]))
               attr_flags[j] |= AF_EXTENDABLE;
      }

   } else {
      memcpy(attr_list, attr_list_default, sizeof(attr_list_default));
      memcpy(attr_options, attr_options_default, sizeof(attr_options_default));
      memcpy(attr_flags, attr_flags_default, sizeof(attr_flags_default));
      n = 4;
   }

   return n;
}

/*------------------------------------------------------------------*/

void show_http_header(BOOL expires)
{
   char str[256];

   rsprintf("HTTP/1.1 200 Document follows\r\n");
   rsprintf("Server: ELOG HTTP %s\r\n", VERSION);

   if (getcfg("global", "charset", str))
      rsprintf("Content-Type: text/html;charset=%s\r\n", str);
   else
      rsprintf("Content-Type: text/html;charset=iso-8859-1\r\n");

   if (use_keepalive) {
      rsprintf("Connection: Keep-Alive\r\n");
      rsprintf("Keep-Alive: timeout=60, max=10\r\n");
   }

   if (expires) {
      rsprintf("Pragma: no-cache\r\n");
      rsprintf("Expires: Fri, 01 Jan 1983 00:00:00 GMT\r\n");
   }

   rsprintf("\r\n");
}

void show_plain_header(int size)
{
   /* header */
   rsprintf("HTTP/1.1 200 Document follows\r\n");
   rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
   rsprintf("Accept-Ranges: bytes\r\n");

   if (use_keepalive) {
      rsprintf("Connection: Keep-Alive\r\n");
      rsprintf("Keep-Alive: timeout=60, max=10\r\n");
   }

   rsprintf("Pragma: no-cache\r\n");
   rsprintf("Expires: Fri, 01 Jan 1983 00:00:00 GMT\r\n");
   rsprintf("Content-Type: text/plain\r\n");
   if (size)
      rsprintf("Content-Length: %d\r\n", size);
   rsprintf("\r\n");
}

void show_html_header(LOGBOOK * lbs, BOOL expires, char *title, BOOL close_head)
{
   char css[256], str[256];

   show_http_header(expires);

   /* DOCTYPE */
   rsprintf("<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">\n");

   /* page title */
   rsprintf("<html><head><title>%s</title>\n", title);

   /* Cascading Style Sheet */
   strlcpy(css, "default.css", sizeof(css));

   if (lbs != NULL && getcfg(lbs->name, "CSS", str))
      strlcpy(css, str, sizeof(css));

   else if (lbs == NULL && getcfg("global", "CSS", str))
      strlcpy(css, str, sizeof(css));

   rsprintf("<link rel=\"stylesheet\" type=\"text/css\" href=\"%s\">\n", css);

   if (close_head)
      rsprintf("</head>\n");
}

void show_standard_header(LOGBOOK * lbs, BOOL expires, char *title, char *path)
{
   show_html_header(lbs, expires, title, TRUE);

   rsprintf("<body>\n");

   show_top_text(lbs);

   if (path)
      rsprintf("<form name=form1 method=\"GET\" action=\"%s\">\n\n", path);
   else
      rsprintf("<form name=form1 method=\"GET\" action=\"\">\n\n");
}

/*------------------------------------------------------------------*/

void show_upgrade_page(LOGBOOK * lbs)
{
   char str[1000];

   show_html_header(lbs, FALSE, "ELOG Upgrade Information", TRUE);

   rsprintf("<body>\n");

   rsprintf("<table class=\"frame\" cellpadding=0 cellspacing=0>\n\n");

   rsprintf
       ("<tr><td class=\"title2\">ELog Electronic Logbook Upgrade Information</font></td></tr>\n");

   rsprintf("<tr><td class=\"form1\"><br>\n");

   rsprintf
       ("You probably use an <b>elogd.cfg</b> configuration file for a ELOG version\n");
   rsprintf
       ("1.1.x, since it contains a <b><code>\"Types = ...\"</code></b> entry. From version\n");
   rsprintf("1.2.0 on, the fixed attributes <b>Type</b> and <b>Category</b> have been\n");
   rsprintf
       ("replaced by arbitrary attributes. Please replace these two lines with the\n");
   rsprintf("following entries:<p>\n");
   rsprintf("<pre>\n");
   rsprintf("Attributes = Author, Type, Category, Subject\n");
   rsprintf("Required Attributes = Author\n");
   getcfg(lbs->name, "Types", str);
   rsprintf("Options Type = %s\n", str);
   getcfg(lbs->name, "Categories", str);
   rsprintf("Options Category = %s\n", str);
   rsprintf("Page title = $subject\n");
   rsprintf("</pre>\n");
   rsprintf("<p>\n");

   rsprintf
       ("It is of course possible to change the attributes or add new ones. The new\n");
   rsprintf("options in the configuration file are described under <a href=\"\n");
   rsprintf
       ("http://midas.psi.ch/elog/config.html\">http://midas.psi.ch/elog/config.html\n");
   rsprintf("</a>.\n");

   rsprintf("</td></tr></table>\n\n");

   rsprintf("<hr>\n");
   rsprintf("<address>\n");
   rsprintf("<a href=\"http://midas.psi.ch/~stefan\">S. Ritt</a>, 18 October 2001");
   rsprintf("</address>");
   show_bottom_text(lbs);
   rsprintf("</body></html>\r\n");
}

/*------------------------------------------------------------------*/

LBLIST get_logbook_hierarchy(void)
{
   int i, j, k, n, m, flag;
   char str[1000], grpname[256], grpmembers[1000];
   LBLIST root;
   char grplist[MAX_N_LIST][NAME_LENGTH];

   /* allocate root node */
   root = malloc(sizeof(LBNODE));
   memset(root, 0, sizeof(LBNODE));

   /* enumerate groups */
   for (i = n = 0;; i++) {
      if (!enumcfg("global", grpname, grpmembers, i))
         break;

      flag = 0;
      strlcpy(str, grpname, sizeof(str));
      str[9] = 0;
      if (equal_ustring(str, "top group"))
         flag = 2;
      str[5] = 0;
      if (equal_ustring(str, "group"))
         flag = 1;

      if (flag) {

         /* allocate new node, increase member pointer array by one */
         if (n == 0)
            root->member = malloc(sizeof(void *));
         else
            root->member = realloc(root->member, (n + 1) * sizeof(void *));
         root->member[n] = malloc(sizeof(LBNODE));

         if (strlen(grpname) < 7)
            strlcpy(root->member[n]->name, "Invalid group definition!", 256);
         else if (flag == 1)
            strlcpy(root->member[n]->name, grpname + 6, 256);
         else
            strlcpy(root->member[n]->name, grpname + 10, 256);

         m = strbreak(grpmembers, grplist, MAX_N_LIST);
         root->member[n]->n_members = m;

         root->member[n]->member = calloc(sizeof(void *), m);
         root->member[n]->n_members = m;
         for (j = 0; j < m; j++) {
            root->member[n]->member[j] = calloc(sizeof(LBNODE), 1);
            strlcpy(root->member[n]->member[j]->name, grplist[j], 256);
         }

         root->member[n]->is_top = (flag == 2);

         n++;
      }
   }

   root->n_members = n;

   /* populate nodes with logbooks or other groups */
   for (i = 0; i < root->n_members; i++)
      if (root->member[i]) {
         for (j = 0; j < root->member[i]->n_members; j++) {
            /* check if node is valid logbook */
            for (k = 0; lb_list[k].name[0]; k++)
               if (equal_ustring(root->member[i]->member[j]->name, lb_list[k].name))
                  break;

            /* check if node is subgroup of other node */
            if (!lb_list[k].name[0]) {
               for (k = 0; k < root->n_members; k++)
                  if (equal_ustring
                      (root->member[i]->member[j]->name, root->member[k]->name)) {

                     /* node is allocated twice, so free one... */
                     free(root->member[i]->member[j]);

                     /* ... and reference the other */
                     root->member[i]->member[j] = root->member[k];

                     /* mark original pointer invalid */
                     root->member[k] = NULL;
                     break;
                  }
            }
         }
      }

   /* remove empty slots */
   for (i = 0; i < root->n_members; i++)
      if (root->member[i] == NULL) {
         for (j = i + 1; j < root->n_members; j++)
            if (root->member[j])
               break;

         if (j < root->n_members && root->member[j]) {
            root->member[i] = root->member[j];
            root->member[j] = NULL;
         }
      }

   for (i = 0; i < root->n_members; i++)
      if (root->member[i] == NULL)
         break;
   if (i < root->n_members)
      root->n_members = i;

   if (n == 0) {
      for (n = 0; lb_list[n].name[0]; n++);

      /* make simple list with logbooks */
      root->member = calloc(n, sizeof(void *));
      root->n_members = n;

      for (i = 0; i < n; i++) {
         root->member[i] = calloc(1, sizeof(LBNODE));
         strlcpy(root->member[i]->name, lb_list[i].name, 256);
      }
   }

   return root;
}

/*------------------------------------------------------------------*/

void free_logbook_hierarchy(LBLIST root)
{
   int i;

   for (i = 0; i < root->n_members; i++) {
      if (root->member[i]) {
         free_logbook_hierarchy(root->member[i]);
         root->member[i] = NULL;
      }
   }

   free(root->member);
   free(root);
}

/*------------------------------------------------------------------*/

int is_logbook_in_group(LBLIST pgrp, char *logbook)
/* test if "logbook" is in group node plb */
{
   int i;

   if (equal_ustring(pgrp->name, logbook))
      return 1;

   for (i = 0; i < pgrp->n_members; i++) {
      if (equal_ustring(logbook, pgrp->member[i]->name))
         return 1;

      if (pgrp->member[i]->n_members > 0 && is_logbook_in_group(pgrp->member[i], logbook))
         return 1;
   }

   return 0;
}

/*------------------------------------------------------------------*/

void show_standard_title(char *logbook, char *text, int printable)
{
   char str[256], ref[256], sclass[32];
   int i, j, level;
   LBLIST phier, pnode, pnext, flb;

   if (printable)
      rsprintf
          ("<table class=\"pframe\" cellpadding=0 cellspacing=0><!-- show_standard_title -->\n\n");
   else
      rsprintf
          ("<table class=\"frame\" cellpadding=0 cellspacing=0><!-- show_standard_title -->\n\n");

   /* scan logbook hierarchy */
   phier = get_logbook_hierarchy();

   /*---- logbook selection row ----*/

   pnode = phier;               /* start at root of tree */
   pnext = NULL;

   if (!printable && getcfg(logbook, "logbook tabs", str)
       && atoi(str) == 1) {

      for (level = 0;; level++) {
         rsprintf("<tr><td class=\"tabs\">\n");

         if (level == 0 && getcfg("global", "main tab", str))
            rsprintf("<span class=\"ltab\"><a href=\"../\">%s</a></span>\n", str);

         /* iterate through members of this group */
         for (i = 0; i < pnode->n_members; i++) {

            if (getcfg(pnode->member[i]->name, "Hidden", str) && atoi(str) == 1)
               continue;

            strlcpy(str, pnode->member[i]->name, sizeof(str));

            /* build reference to first logbook in group */
            if (pnode->member[i]->member == NULL)
               strlcpy(ref, str, sizeof(ref));  // current node is logbook
            else {
               flb = pnode->member[i]->member[0];       // current node is group
               while (flb->member)      // so traverse hierarchy
                  flb = flb->member[0];
               strlcpy(ref, flb->name, sizeof(ref));
            }
            url_encode(ref, sizeof(ref));

            if (is_logbook_in_group(pnode->member[i], logbook)) {

               /* remember member list of this group for next row */
               pnext = pnode->member[i];

               if (pnode->member[i]->member == NULL)
                  /* selected logbook */
                  strcpy(sclass, "sltab");
               else
                  /* selected group */
                  strcpy(sclass, "sgtab");
            } else {
               if (pnode->member[i]->member == NULL)
                  /* unselected logbook */
                  strcpy(sclass, "ltab");
               else
                  /* unselected group */
                  strcpy(sclass, "gtab");
            }

            if (!pnode->member[i]->is_top) {

               rsprintf("<span class=\"%s\"><a href=\"../%s/\">", sclass, ref);

               strlcpy(str, pnode->member[i]->name, sizeof(str));

               for (j = 0; j < (int) strlen(str); j++)
                  if (str[j] == ' ')
                     rsprintf("&nbsp;");
                  else
                     rsprintf("%c", str[j]);

               rsprintf("</a></span>\n");
            }
         }

         rsprintf("</td></tr>\n\n");

         pnode = pnext;
         pnext = NULL;

         if (pnode == NULL)
            break;
      }
   }

   free_logbook_hierarchy(phier);

   /*---- title row ----*/

   rsprintf("<tr><td><table width=\"100%%\" border=0 cellpadding=0 cellspacing=0>\n");

   /* left cell */
   rsprintf("<tr><td class=\"title1\">");

   /* use comment as title if available, else logbook name */
   if (!getcfg(logbook, "Comment", str))
      strcpy(str, logbook);

   rsprintf("&nbsp;&nbsp;%s%s&nbsp;</td>\n", str, text);

   /* middle cell */
   if (*getparam("full_name"))
      rsprintf("<td class=\"title2\">%s \"%s\"</td>\n", loc("Logged in as"),
               getparam("full_name"));
   else if (getcfg(logbook, "Guest menu commands", str))
      rsprintf("<td class=\"title2\" align=center>%s</td>\n", loc("Not logged in"));

   /* right cell */
   rsprintf("<td class=\"title3\">");

   if (getcfg(logbook, "Title image URL", str))
      rsprintf("<a href=\"%s\">\n", str);

   if (getcfg(logbook, "Title image", str))
      rsprintf(str);
   else
      rsprintf("<img border=0 src=\"elog.gif\" alt=\"ELOG logo\">");

   if (getcfg(logbook, "Title image URL", str))
      rsprintf("</a>\n");

   rsprintf("</td>\n");

   rsprintf("</tr></table></td></tr>\n\n");
}

/*------------------------------------------------------------------*/

void show_top_text(LOGBOOK * lbs)
{
   char str[NAME_LENGTH];
   int size;

   if (getcfg(lbs->name, "top text", str)) {
      FILE *f;
      char file_name[256], *buf;

      /* check if file starts with an absolute directory */
      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strcpy(file_name, str);
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }

      f = fopen(file_name, "rb");
      if (f != NULL) {
         fseek(f, 0, SEEK_END);
         size = TELL(fileno(f));
         fseek(f, 0, SEEK_SET);

         buf = malloc(size + 1);
         fread(buf, 1, size, f);
         buf[size] = 0;
         fclose(f);

         rsputs(buf);
      } else
         rsputs(file_name);
   }
}

/*------------------------------------------------------------------*/

void show_bottom_text(LOGBOOK * lbs)
{
   char str[NAME_LENGTH];
   int size;

   if (getcfg(lbs->name, "bottom text", str)) {
      FILE *f;
      char file_name[256], *buf;

      /* check if file starts with an absolute directory */
      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strcpy(file_name, str);
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }

      f = fopen(file_name, "rb");
      if (f != NULL) {
         fseek(f, 0, SEEK_END);
         size = TELL(fileno(f));
         fseek(f, 0, SEEK_SET);

         buf = malloc(size + 1);
         fread(buf, 1, size, f);
         buf[size] = 0;
         fclose(f);

         rsputs(buf);
      } else
         rsputs(file_name);
   } else
      /* add little logo */
      rsprintf
          ("<center><a class=\"bottomlink\" href=\"http://midas.psi.ch/elog/\">ELOG V%s</a></center>",
           VERSION);
}

/*------------------------------------------------------------------*/

void show_error(char *error)
{
   /* header */
   show_html_header(NULL, FALSE, "ELOG error", TRUE);

   rsprintf("<body><center>\n");
   rsprintf("<table class=\"dlgframe\" width=\"50%%\" cellpadding=1 cellspacing=0");
   rsprintf("<tr><td class=\"errormsg\">%s</td></tr>\n", error);

   rsprintf("<tr><td class=\"errormsg\">");

   /*
      rsprintf("<script language=\"javascript\" type=\"text/javascript\">\n");
      rsprintf("if (!navigator.javaEnabled()) {\n");
      rsprintf("  document.write(\"%s\")\n", loc("Please use your browser's back button to go back"));
      rsprintf("} else {\n");
      rsprintf("  document.write(\"<button type=button onClick=history.back()>%s</button>\")\n", loc("Back"));
      rsprintf("} \n");
      rsprintf("</script>\n");

      rsprintf("<noscript>\n");
    */

   rsprintf("%s\n", loc("Please use your browser's back button to go back"));

   /*
      rsprintf("</noscript>\n");
    */

   rsprintf("</td></tr>\n</table>\n");
   rsprintf("</center></body></html>\n");
}

/*------------------------------------------------------------------*/

void set_login_cookies(LOGBOOK * lbs, char *user, char *enc_pwd)
{
   char str[256], lb_name[256], exp[80];
   BOOL global;

   rsprintf("HTTP/1.1 302 Found\r\n");
   rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
   if (use_keepalive) {
      rsprintf("Connection: Keep-Alive\r\n");
      rsprintf("Keep-Alive: timeout=60, max=10\r\n");
   }

   if (lbs)
      strcpy(lb_name, lbs->name);
   else
      strcpy(lb_name, "global");

   /* get optional expriation from configuration file */
   if (isparam("remember")) {
      if (!getcfg(lb_name, "Login expiration", exp))
         strcpy(exp, "31*24");  /* one month by default */
   } else
      exp[0] = 0;

   /* check if cookies should be global */
   global = getcfg("global", "Password file", str);

   /* two cookies for password and user name */
   set_cookie(lbs, "unm", user, global, exp);
   set_cookie(lbs, "upwd", enc_pwd, global, exp);

   set_redir(lbs, getparam("redir"));
}

/*------------------------------------------------------------------*/

int exist_file(char *file_name)
{
   int fh;

   fh = open(file_name, O_RDONLY | O_BINARY);
   if (fh > 0) {
      close(fh);
      return 1;
   }
   return 0;
}

/*------------------------------------------------------------------*/

void send_file_direct(char *file_name)
{
   int fh, i, length, delta;
   char str[MAX_PATH_LENGTH];
   time_t now;
   struct tm *gmt;

   fh = open(file_name, O_RDONLY | O_BINARY);
   if (fh > 0) {
      lseek(fh, 0, SEEK_END);
      length = TELL(fh);
      lseek(fh, 0, SEEK_SET);

      rsprintf("HTTP/1.1 200 Document follows\r\n");
      rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
      rsprintf("Accept-Ranges: bytes\r\n");

      /* set expiration time to one day */
      time(&now);
      now += (int) (3600 * 24);
      gmt = gmtime(&now);
      strftime(str, sizeof(str), "%A, %d-%b-%y %H:%M:%S GMT", gmt);
      rsprintf("Expires: %s\r\n", str);

      if (use_keepalive) {
         rsprintf("Connection: Keep-Alive\r\n");
         rsprintf("Keep-Alive: timeout=60, max=10\r\n");
      }

      /* return proper header for file type */
      for (i = 0; i < (int) strlen(file_name); i++)
         str[i] = toupper(file_name[i]);
      str[i] = 0;

      for (i = 0; filetype[i].ext[0]; i++)
         if (strstr(str, filetype[i].ext))
            break;

      if (filetype[i].ext[0])
         rsprintf("Content-Type: %s\r\n", filetype[i].type);
      else if (strchr(str, '.') == NULL)
         rsprintf("Content-Type: text/plain\r\n");
      else
         rsprintf("Content-Type: application/octet-stream\r\n");

      rsprintf("Content-Length: %d\r\n\r\n", length);

      /* increase return buffer size if file too big */
      if (length > return_buffer_size - (int) strlen(return_buffer)) {
         delta = length - (return_buffer_size - strlen(return_buffer)) + 1000;

         return_buffer = realloc(return_buffer, return_buffer_size + delta);
         memset(return_buffer + return_buffer_size, 0, delta);
         return_buffer_size += delta;
      }

      return_length = strlen(return_buffer) + length;
      read(fh, return_buffer + strlen(return_buffer), length);

      close(fh);
   } else {
      show_html_header(NULL, FALSE, "404 Not Found", TRUE);

      rsprintf("<body><h1>Not Found</h1>\r\n");
      rsprintf("The requested file <b>%s</b> was not found on this server<p>\r\n",
               file_name);
      rsprintf("<hr><address>ELOG version %s</address></body></html>\r\n\r\n", VERSION);
      return_length = strlen_retbuf;
      keep_alive = 0;
   }
}

/*------------------------------------------------------------------*/

void strencode(char *text)
{
   int i;

   for (i = 0; i < (int) strlen(text); i++) {
      switch (text[i]) {
      case '\n':
         rsprintf("<br>\n");
         break;
      case '<':
         rsprintf("&lt;");
         break;
      case '>':
         rsprintf("&gt;");
         break;
      case '&':
         rsprintf("&amp;");
         break;
      case '\"':
         rsprintf("&quot;");
         break;
      case ' ':
         rsprintf("&nbsp;");
         break;

         /* the translation for the search highliting */
      case '\001':
         rsprintf("<");
         break;
      case '\002':
         rsprintf(">");
         break;
      case '\003':
         rsprintf("\"");
         break;
      case '\004':
         rsprintf(" ");
         break;

      default:
         rsprintf("%c", text[i]);
      }
   }
}

/*------------------------------------------------------------------*/

void strencode2(char *b, char *text)
{
   int i;

   for (i = 0; i < (int) strlen(text); b++, i++) {
      switch (text[i]) {
      case '\n':
         sprintf(b, "<br>\n");
         break;
      case '<':
         sprintf(b, "&lt;");
         break;
      case '>':
         sprintf(b, "&gt;");
         break;
      case '&':
         sprintf(b, "&amp;");
         break;
      case '\"':
         sprintf(b, "&quot;");
         break;
      default:
         sprintf(b, "%c", text[i]);
      }
   }
   *b = 0;
}

/*------------------------------------------------------------------*/

int build_subst_list(LOGBOOK * lbs, char list[][NAME_LENGTH], char value[][NAME_LENGTH],
                     char attrib[][NAME_LENGTH])
{
   int i;
   char str[NAME_LENGTH], format[256];
   time_t now;
   struct tm *ts;

   /* copy attribute list */
   i = 0;
   if (attrib != NULL)
      for (; i < lbs->n_attr; i++) {
         strcpy(list[i], attr_list[i]);
         if (attrib)
            strcpy(value[i], attrib[i]);
         else
            strcpy(value[i], getparam(attr_list[i]));
      }

   /* add remote host */
   strcpy(list[i], "remote_host");
   strlcpy(value[i++], rem_host, NAME_LENGTH);

   /* add local host */
   strcpy(list[i], "host");
   strlcpy(value[i++], host_name, NAME_LENGTH);

   /* add user names */
   strcpy(list[i], "short_name");
   strlcpy(value[i++], getparam("unm"), NAME_LENGTH);
   strcpy(list[i], "long_name");
   strlcpy(value[i++], getparam("full_name"), NAME_LENGTH);

   /* add email */
   strcpy(list[i], "user_email");
   strcpy(value[i], "mailto:");
   strlcat(value[i++], getparam("user_email"), NAME_LENGTH);

   /* add logbook */
   strcpy(list[i], "logbook");
   strlcpy(value[i++], lbs->name, NAME_LENGTH);

   /* add date */
   strcpy(list[i], "date");
   time(&now);
   ts = localtime(&now);
   if (!getcfg(lbs->name, "Date format", format))
      strcpy(format, DEFAULT_DATE_FORMAT);

   strftime(str, sizeof(str), format, ts);

   strcpy(value[i++], str);

   return i;
}

/*------------------------------------------------------------------*/

BOOL change_pwd(LOGBOOK * lbs, char *user, char *pwd)
{
   char str[256], file_name[256], line[256], *p, *pl;
   char *buf;
   int i, fh, size;

   getcfg(lbs->name, "Password file", str);

   if (str[0] == DIR_SEPARATOR || str[1] == ':')
      strcpy(file_name, str);
   else {
      strlcpy(file_name, resource_dir, sizeof(file_name));
      strlcat(file_name, str, sizeof(file_name));
   }

   fh = open(file_name, O_RDWR | O_BINARY, 644);
   if (fh > 0) {
      lseek(fh, 0, SEEK_END);
      size = TELL(fh);
      lseek(fh, 0, SEEK_SET);

      buf = malloc(size + 1);
      read(fh, buf, size);
      buf[size] = 0;
      pl = buf;

      while (pl < buf + size) {
         for (i = 0; pl[i] && pl[i] != '\r' && pl[i] != '\n'; i++)
            line[i] = pl[i];
         line[i] = 0;

         if (line[0] == ';' || line[0] == '#' || line[0] == 0) {
            pl += strlen(line);
            while (*pl && (*pl == '\r' || *pl == '\n'))
               pl++;
            continue;
         }

         strcpy(str, line);
         if (strchr(str, ':'))
            *strchr(str, ':') = 0;
         if (strcmp(str, user) == 0)
            break;

         pl += strlen(line);
         while (*pl && (*pl == '\r' || *pl == '\n'))
            pl++;
      }

      /* return if not found */
      if (pl >= buf + size) {
         free(buf);
         close(fh);
         return FALSE;
      }

      p = strchr(line, ':');
      if (p)
         p = strchr(p + 1, ':');
      if (p == NULL)
         return FALSE;

      /* replace password */
      lseek(fh, 0, SEEK_SET);
      write(fh, buf, pl - buf);

      sprintf(str, "%s:%s%s\n", user, pwd, p);
      write(fh, str, strlen(str));

      pl += strlen(line);
      while (*pl && (*pl == '\r' || *pl == '\n'))
         pl++;

      write(fh, pl, strlen(pl));

#ifdef _MSC_VER
      chsize(fh, TELL(fh));
#else
      ftruncate(fh, TELL(fh));
#endif

      free(buf);
      close(fh);

      return TRUE;
   }

   return FALSE;
}

/*------------------------------------------------------------------*/

void show_change_pwd_page(LOGBOOK * lbs)
{
   char str[256], old_pwd[32], new_pwd[32], new_pwd2[32], act_pwd[32], user[80];
   int wrong_pwd;

   do_crypt(getparam("oldpwd"), old_pwd);
   do_crypt(getparam("newpwd"), new_pwd);
   do_crypt(getparam("newpwd2"), new_pwd2);

   strcpy(user, getparam("unm"));
   if (isparam("config"))
      strcpy(user, getparam("config"));

   wrong_pwd = FALSE;

   if (old_pwd[0] || new_pwd[0]) {
      if (user[0]
          && get_user_line(lbs->name, user, act_pwd, NULL, NULL, NULL)) {
         /* administrator does not have to supply old password */
         if (getcfg(lbs->name, "Admin user", str) && strstr(str, getparam("unm")) != 0)
            wrong_pwd = 0;
         else {
            if (strcmp(old_pwd, act_pwd) != 0)
               wrong_pwd = 1;
         }

         if (strcmp(new_pwd, new_pwd2) != 0)
            wrong_pwd = 2;
      }

      /* replace password */
      if (!wrong_pwd)
         change_pwd(lbs, user, new_pwd);

      if (!wrong_pwd && strcmp(user, getparam("unm")) == 0) {
         set_login_cookies(lbs, user, new_pwd);
         return;
      }

      if (!wrong_pwd) {
         /* redirect back to configuration page */
         sprintf(str, "?cmd=%s&cfg_user=%s", loc("Config"), getparam("config"));
         redirect(lbs, str);
         return;
      }
   }

   show_standard_header(lbs, TRUE, loc("ELOG change password"), NULL);

   rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");

   if (wrong_pwd == 1)
      rsprintf("<tr><td colspan=2 class=\"dlgerror\">%s!</td></tr>\n",
               loc("Wrong password"));

   if (wrong_pwd == 2)
      rsprintf("<tr><td colspan=2 class=\"dlgerror\">%s!</td></tr>\n",
               loc("New passwords do not match, please retype"));

   rsprintf("<tr><td colspan=2 class=\"dlgtitle\">\n");

   rsprintf("<input type=hidden name=config value=\"%s\">", user);

   rsprintf("%s \"%s\"</td></tr>\n", loc("Change password for user"), user);

   if (!getcfg(lbs->name, "Admin user", str) || !strstr(str, getparam("unm")) != 0) {
      if (isparam("old_pwd"))
         rsprintf("<input type=hidden name=oldpwd value=\"%s\"", getparam("old_pwd"));
      else {
         rsprintf("<tr><td align=right class=\"dlgform\">%s:\n", loc("Old password"));
         rsprintf("<td align=left class=\"dlgform\"><input type=password name=oldpwd>\n");
         rsprintf("</td></tr>\n");
      }
   }

   rsprintf("<tr><td align=right class=\"dlgform\">%s:</td>\n", loc("New password"));
   rsprintf
       ("<td align=left class=\"dlgform\"><input type=password name=newpwd></td></tr>\n");

   rsprintf("<tr><td align=right class=\"dlgform\">%s:</td>\n",
            loc("Retype new password"));
   rsprintf
       ("<td align=left class=\"dlgform\"><input type=password name=newpwd2></td></tr>\n");

   rsprintf
       ("<tr><td align=center colspan=2 class=\"dlgform\"><input type=submit value=\"%s\"></td></tr>",
        loc("Submit"));

   rsprintf("</table>\n");
   show_bottom_text(lbs);
   rsprintf("</form></body></html>\r\n");
}

/*------------------------------------------------------------------*/

int get_last_index(LOGBOOK * lbs, int index)
/* return value of specific attribute of last entry, can be used to
auto-increment tags */
{
   int i, message_id;
   char str[80], attrib[MAX_N_ATTR][NAME_LENGTH], att[MAX_ATTACHMENTS][256];

   str[0] = 0;
   message_id = el_search_message(lbs, EL_LAST, 0, FALSE);

   el_retrieve(lbs, message_id, NULL, attr_list, attrib, lbs->n_attr, NULL, 0, NULL, NULL,
               att, NULL, NULL);

   strcpy(str, attrib[index]);

   /* look for first digit, return value */
   for (i = 0; i < (int) strlen(str); i++)
      if (isdigit(str[i]))
         break;

   return atoi(str + i);
}

/*------------------------------------------------------------------*/

BOOL is_author(LOGBOOK * lbs, char attrib[MAX_N_ATTR][NAME_LENGTH], char *owner)
{
   char str[1000], preset[1000];
   int i;

   /* check if current user is admin */
   if (getcfg(lbs->name, "Admin user", str)
       && strstr(str, getparam("unm")) != 0)
      return TRUE;

   /* search attribute which contains short_name of author */
   for (i = 0; i < lbs->n_attr; i++) {
      sprintf(str, "Preset %s", attr_list[i]);
      if (getcfg(lbs->name, str, preset)) {
         if (strstr(preset, "$short_name")) {
            if (strstr(attrib[i], getparam("unm")) == NULL) {
               strcpy(owner, attrib[i]);
               return FALSE;
            } else
               break;
         }
      }
   }

   if (i == lbs->n_attr) {
      /* if not found, search attribute which contains full_name of author */
      for (i = 0; i < lbs->n_attr; i++) {
         sprintf(str, "Preset %s", attr_list[i]);
         if (getcfg(lbs->name, str, preset)) {
            if (strstr(preset, "$long_name")) {
               if (strstr(attrib[i], getparam("full_name")) == NULL) {
                  strcpy(owner, attrib[i]);
                  return FALSE;
               }
            }
         }
      }
   }

   return TRUE;
}

/*------------------------------------------------------------------*/

BOOL is_cond_attr(index)
{
   int i;

   for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++)
      if (strchr(attr_options[index][i], '{') && strchr(attr_options[index][i], '}'))
         return TRUE;

   return FALSE;
}

/*------------------------------------------------------------------*/

void show_edit_form(LOGBOOK * lbs, int message_id, BOOL breply, BOOL bedit, BOOL bupload,
                    BOOL breedit)
{
   int i, j, n, index, size, width, height, fh, length, first, input_size, input_maxlen,
       format_flags;
   char str[1000], preset[1000], *p, *pend, star[80], comment[10000], reply_string[256],
       list[MAX_N_ATTR][NAME_LENGTH], file_name[256], *buffer, format[256], date[80],
       attrib[MAX_N_ATTR][NAME_LENGTH], text[TEXT_SIZE], orig_tag[80],
       reply_tag[MAX_REPLY_TO * 10], att[MAX_ATTACHMENTS][256], encoding[80],
       slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH],
       owner[256], locked_by[256], class_value[80], class_name[80], condition[256],
       ua[NAME_LENGTH];
   time_t now;
   char fl[8][NAME_LENGTH];
   struct tm *pts, ts;

   for (i = 0; i < MAX_ATTACHMENTS; i++)
      att[i][0] = 0;

   for (i = 0; i < lbs->n_attr; i++)
      attrib[i][0] = 0;

   text[0] = 0;

   if (breedit || bupload) {
      /* get date from parameter */
      if (*getparam("entry_date"))
         strcpy(date, getparam("entry_date"));

      /* get attributes from parameters */
      for (i = 0; i < lbs->n_attr; i++) {
         strcpy(ua, attr_list[i]);
         btou(ua);
         if (attr_flags[i] & AF_MULTI) {
            attrib[i][0] = 0;
            first = 1;
            for (j = 0; j < MAX_N_LIST; j++) {
               sprintf(str, "%s#%d", ua, j);
               if (getparam(str)) {
                  if (*getparam(str)) {
                     if (first)
                        first = 0;
                     else
                        strlcat(attrib[i], " | ", NAME_LENGTH);
                     if (strlen(attrib[i]) + strlen(getparam(str)) < NAME_LENGTH - 2)
                        strlcat(attrib[i], getparam(str), NAME_LENGTH);
                     else
                        break;
                  }
               } else
                  break;
            }
         } else {
            strlcpy(attrib[i], getparam(ua), NAME_LENGTH);
         }
      }

      strlcpy(text, getparam("text"), TEXT_SIZE);

      for (i = 0; i < MAX_ATTACHMENTS; i++) {
         sprintf(str, "attachment%d", i);
         if (isparam(str))
            strlcpy(att[i], getparam(str), 256);
      }

      /* get encoding */
      strcpy(encoding, atoi(getparam("html")) == 1 ? "HTML" : "plain");
   } else {
      if (message_id) {
         /* get message for reply/edit */

         size = sizeof(text);
         el_retrieve(lbs, message_id, date, attr_list, attrib, lbs->n_attr,
                     text, &size, orig_tag, reply_tag, att, encoding, locked_by);

         if (bedit) {
            if (getcfg(lbs->name, "Use Lock", str) && atoi(str) == 1) {
               if (*getparam("full_name"))
                  strcpy(str, getparam("full_name"));
               else
                  strcpy(str, loc("user"));

               strcat(str, " ");
               strcat(str, loc("on"));
               strcat(str, " ");
               strcat(str, rem_host);

               el_lock_message(lbs, message_id, str);
            }
         }
      } else {
         /* get preset attributes */
         for (i = 0; i < lbs->n_attr; i++) {
            sprintf(str, "p%s", attr_list[i]);
            strcpy(attrib[i], getparam(str));
         }
      }
   }

   /* evaluate conditional attributes */
   condition[0] = 0;
   for (i = 0; i < lbs->n_attr; i++) {
      if (strchr(attrib[i], '{') && strchr(attrib[i], '}')) {
         strlcpy(str, strchr(attrib[i], '{') + 1, sizeof(str));
         if (*strchr(str, '}'))
            *strchr(str, '}') = 0;

         if (condition[0] == 0)
            strlcpy(condition, str, sizeof(condition));
         else {
            strlcat(condition, ",", sizeof(condition));
            strlcat(condition, str, sizeof(condition));
         }
      }
   }

   /* check for maximum number of replies */
   if (breply) {
      i = 0;
      p = strtok(reply_tag, ",");
      while (p) {
         i++;
         p = strtok(NULL, ",");
      }

      if (i >= MAX_REPLY_TO) {
         sprintf(str, loc("Maximum number of replies (%d) exceeded"), MAX_REPLY_TO);
         show_error(str);
         return;
      }
   }

   /* check for author */
   if (bedit && getcfg_cond(lbs->name, condition, "Restrict edit", str)
       && atoi(str) == 1) {
      if (!is_author(lbs, attrib, owner)) {
         sprintf(str, loc("Only user <i>%s</i> can edit this entry"), owner);
         show_error(str);
         return;
      }
   }

   /* check for editing interval */
   if (bedit && getcfg_cond(lbs->name, condition, "Restrict edit time", str)) {
      for (i = 0; i < *lbs->n_el_index; i++)
         if (lbs->el_index[i].message_id == message_id)
            break;

      if (i < *lbs->n_el_index
          && time(NULL) > lbs->el_index[i].file_time + atof(str) * 3600) {
         sprintf(str, loc("Entry can only be edited %1.2lg hours after creation"),
                 atof(str));
         show_error(str);
         return;
      }
   }

   /* remove attributes for replies */
   if (breply) {
      getcfg_cond(lbs->name, condition, "Remove on reply", str);
      n = strbreak(str, list, MAX_N_ATTR);
      for (i = 0; i < n; i++)
         for (j = 0; j < lbs->n_attr; j++) {
            if (equal_ustring(attr_list[j], list[i]))
               attrib[j][0] = 0;
         }
   }

   /* subst attributes for replies */
   if (breply) {
      for (index = 0; index < lbs->n_attr; index++) {
         sprintf(str, "Subst on reply %s", attr_list[index]);
         if (getcfg_cond(lbs->name, condition, str, preset)) {
            /* check if already second reply */
            if (orig_tag[0] == 0) {
               i = build_subst_list(lbs, slist, svalue, attrib);
               strsubst(preset, slist, svalue, i);
               strcpy(attrib[index], preset);
            }
         }
      }
   }

   /* subst attributes for edits */
   if (message_id && bedit && !breedit && !bupload) {
      for (index = 0; index < lbs->n_attr; index++) {
         sprintf(str, "Subst on edit %s", attr_list[index]);
         if (getcfg_cond(lbs->name, condition, str, preset)) {
            i = build_subst_list(lbs, slist, svalue, attrib);
            strsubst(preset, slist, svalue, i);
            if (strncmp(preset, "<br>", 4) == 0)
               strcpy(attrib[index], preset + 4);
            else
               strcpy(attrib[index], preset);
         }
      }
   }

   /* header */
   show_html_header(lbs, FALSE, "ELOG", FALSE);

   /* java script for checking required attributes */
   rsprintf("<script type=\"text/javascript\">\n");
   rsprintf("<!--\n");
   rsprintf("function chkform()\n");
   rsprintf("{\n");

   for (i = 0; i < lbs->n_attr; i++)
      if (attr_flags[i] & AF_REQUIRED) {

         /* convert blanks to underscores */
         strcpy(ua, attr_list[i]);
         btou(ua);

         if (attr_flags[i] & AF_MULTI) {
            rsprintf("  if (\n");
            for (j = 0; j < MAX_N_LIST && attr_options[i][j][0]; j++) {
               sprintf(str, "%s_%d", ua, j);
               rsprintf("    !document.form1.%s.checked", str);
               if (attr_options[i][j + 1][0])
                  rsprintf(" &&\n");
            }
            rsprintf(") {\n");
            sprintf(str, loc("Please select at least one '%s'"), attr_list[i]);
            rsprintf("    alert(\"%s\");\n", str);
            rsprintf("    document.form1.%s_0.focus();\n", ua);
            rsprintf("    return false;\n");
            rsprintf("  }\n");

         } else if (attr_flags[i] & AF_RADIO) {
            rsprintf("  for (var i=0 ; i<document.form1.%s.length ; i++)\n", ua);
            rsprintf("    if (document.form1.%s[i].checked) { break }\n", ua);
            rsprintf("  if (i == document.form1.%s.length) {\n", ua);
            sprintf(str, loc("Please select a '%s'"), attr_list[i]);
            rsprintf("    alert(\"%s\");\n", str);
            rsprintf("    document.form1.%s[0].focus();\n", ua);
            rsprintf("    return false;\n");
            rsprintf("  }\n");

         } else {
            rsprintf("  if (document.form1.%s.value == \"\") {\n", ua);
            sprintf(str, loc("Please enter attribute '%s'"), attr_list[i]);
            rsprintf("    alert(\"%s\");\n", str);
            rsprintf("    document.form1.%s.focus();\n", ua);
            rsprintf("    return false;\n");
            rsprintf("  }\n");
         }
      }

   rsprintf("  return true;\n");
   rsprintf("}\n");
   rsprintf("//-->\n");
   rsprintf("</script>\n\n");

   /* external script if requested */
   if (isparam("js")) {
      rsprintf("<script src=\"%s\" type=\"text/javascript\">\n", getparam("js"));
      rsprintf("</script>\n\n");
   }

   rsprintf("</head>\n");

   rsprintf("<body>\n");
   rsprintf("<form name=form1 method=\"POST\" action=\".\" ");
   rsprintf("enctype=\"multipart/form-data\">\n");

   /*---- add password in case cookie expires during edit ----*/

   if (getcfg(lbs->name, "Write password", str))
      rsprintf("<input type=hidden name=\"wpwd\" value=\"%s\">\n", str);

   if (getcfg(lbs->name, "Password file", str)) {
      rsprintf("<input type=hidden name=\"unm\" value=\"%s\">\n", getparam("unm"));
      rsprintf("<input type=hidden name=\"upwd\" value=\"%s\">\n", getparam("upwd"));
   }

   /*---- title row ----*/

   show_standard_title(lbs->name, "", 0);

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

   /* default cmd */
   rsprintf("<input type=hidden name=cmd value=\"%s\">\n", loc("Update"));

   rsprintf
       ("<input type=\"submit\" name=\"cmd\" value=\"%s\" onClick=\"return chkform();\">\n",
        loc("Submit"));
   rsprintf("<input type=\"submit\" name=\"cmd\" value=\"%s\">\n", loc("Back"));
   rsprintf("</span></td></tr>\n\n");

   /*---- entry form ----*/

   /* table for two-column items */
   rsprintf("<tr><td><table class=\"listframe\" width=\"100%%\" cellspacing=0>");

   /* print required message if one of the attributes has it set */
   for (i = 0; i < lbs->n_attr; i++) {
      if (attr_flags[i] & AF_REQUIRED) {
         rsprintf
             ("<tr><td colspan=2 class=\"attribvalue\">%s <font color=red>*</font> %s</td></tr>\n",
              loc("Fields marked with"), loc("are required"));
         break;
      }
   }

   time(&now);
   if (bedit) {
      if (!getcfg_cond(lbs->name, condition, "Date format", format))
         strcpy(format, DEFAULT_DATE_FORMAT);

      memset(&ts, 0, sizeof(ts));

      for (i = 0; i < 12; i++)
         if (strncmp(date + 4, mname[i], 3) == 0)
            break;
      ts.tm_mon = i;

      ts.tm_mday = atoi(date + 8);
      ts.tm_hour = atoi(date + 11);
      ts.tm_min = atoi(date + 14);
      ts.tm_sec = atoi(date + 17);
      ts.tm_year = atoi(date + 20) - 1900;
      ts.tm_isdst = -1;         /* let mktime compute DST */

      mktime(&ts);
      strftime(str, sizeof(str), format, &ts);
   } else {
      if (getcfg_cond(lbs->name, condition, "Date format", format))
         strftime(str, sizeof(str), format, localtime(&now));
      else
         strcpy(str, ctime(&now));
      strcpy(date, ctime(&now));
      date[24] = 0;
   }

   rsprintf("<tr><td nowrap width=\"10%%\" class=\"attribname\">%s:</td>",
            loc("Entry date"));
   rsprintf("<td class=\"attribvalue\">%s\n", str);
   rsprintf("<input type=hidden name=entry_date value=\"%s\"></td></tr>\n", date);

   /* rescan attributes if condition set */
   if (condition[0])
      scan_attributes(lbs->name, condition);

   /* display attributes */
   for (index = 0; index < lbs->n_attr; index++) {
      strcpy(class_name, "attribname");
      strcpy(class_value, "attribvalue");
      input_size = 80;
      input_maxlen = NAME_LENGTH;
      format_flags = 0;
      strcpy(ua, attr_list[index]);
      btou(ua);

      sprintf(str, "Format %s", attr_list[index]);
      if (getcfg_cond(lbs->name, condition, str, format)) {
         n = strbreak(format, fl, 8);
         if (n > 0)
            format_flags = atoi(fl[0]);
         if (n > 1)
            strlcpy(class_name, fl[1], sizeof(class_name));
         if (n > 2)
            strlcpy(class_value, fl[2], sizeof(class_value));
         if (n > 3 && atoi(fl[3]) > 0)
            input_size = atoi(fl[3]);
         if (n > 4 && atoi(fl[4]) > 0)
            input_maxlen = atoi(fl[4]);
      }

      strcpy(star, (attr_flags[index] & AF_REQUIRED) ? "<font color=red>*</font>" : "");

      /* check for preset string */
      sprintf(str, "Preset %s", attr_list[index]);
      if ((i = getcfg_cond(lbs->name, condition, str, preset)) > 0) {

         if (!bedit || (breedit && i == 2)) {   /* subst on reedit only if preset is under condition */

            i = build_subst_list(lbs, slist, svalue, NULL);
            strsubst(preset, slist, svalue, i);

            /* check for index substitution */
            if (!bedit && strchr(preset, '%')) {
               /* get index */
               i = get_last_index(lbs, index);

               strcpy(str, preset);
               sprintf(preset, str, i + 1);
            }

            if (!strchr(preset, '%'))
               strcpy(attrib[index], preset);
         }
      }

      /* display text box */
      rsprintf("<tr><td nowrap class=\"attribname\">%s%s:", attr_list[index], star);

      /* show optional comment */
      sprintf(str, "Comment %s", attr_list[index]);
      if (getcfg_cond(lbs->name, condition, str, comment))
         rsprintf("<br><span class=\"selcomment\"><b>%s</b></span>\n", comment);

      rsprintf("</td>\n");

      /* if attribute cannot be changed, just display text */
      if ((attr_flags[index] & AF_LOCKED) ||
          (bedit && (attr_flags[index] & AF_FIXED_EDIT)) || (message_id && !bedit
                                                             && (attr_flags[index] &
                                                                 AF_FIXED_REPLY))) {
         rsprintf("<td class=\"attribvalue\">\n");
         rsputs2(attrib[index]);
         rsprintf("&nbsp;");

         if (attr_flags[index] & AF_MULTI) {
            for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
               sprintf(str, "%s_%d", ua, i);

               if (strstr(attrib[index], attr_options[index][i]))
                  rsprintf("<input type=\"hidden\" name=\"%s\" value=\"%s\">\n", str,
                           attr_options[index][i]);
            }
         } else if (attr_flags[index] & AF_RADIO) {
            for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
               sprintf(str, "%s_%d", ua, i);

               if (strstr(attrib[index], attr_options[index][i]))
                  rsprintf("<input type=\"hidden\" name=\"%s\" value=\"%s\">\n", str,
                           attr_options[index][i]);
            }
         } else if (attr_flags[index] & AF_ICON) {
            for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
               sprintf(str, "%s_%d", ua, i);

               if (strstr(attrib[index], attr_options[index][i]))
                  rsprintf("<input type=\"hidden\" name=\"%s\" value=\"%s\">\n", str,
                           attr_options[index][i]);
            }
         } else
            rsprintf("<input type=\"hidden\" name=\"%s\" value=\"%s\"></td></tr>\n",
                     ua, attrib[index]);
      } else {
         if (attr_options[index][0][0] == 0) {
            rsprintf
                ("<td class=\"attribvalue\"><input type=\"text\" size=%d maxlength=%d name=\"%s\" value=\"%s\"></td></tr>\n",
                 input_size, input_maxlen, ua, attrib[index]);
         } else {
            if (equal_ustring(attr_options[index][0], "boolean")) {
               /* display checkbox */
               if (atoi(attrib[index]) == 1)
                  rsprintf
                      ("<td class=\"attribvalue\"><input type=checkbox checked name=\"%s\" value=1>\n",
                       ua);
               else
                  rsprintf
                      ("<td class=\"attribvalue\"><input type=checkbox name=\"%s\" value=1>\n",
                       ua);
            } else {
               if (attr_flags[index] & AF_MULTI) {
                  /* display multiple check boxes */
                  rsprintf("<td class=\"attribvalue\">\n");

                  for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
                     sprintf(str, "%s_%d", ua, i);

                     if (strstr(attrib[index], attr_options[index][i]))
                        rsprintf
                            ("<nobr><input type=checkbox checked name=\"%s\" value=\"%s\">%s</nobr>\n",
                             str, attr_options[index][i], attr_options[index][i]);
                     else
                        rsprintf
                            ("<nobr><input type=checkbox name=\"%s\" value=\"%s\">%s</nobr>\n",
                             str, attr_options[index][i], attr_options[index][i]);

                     if (format_flags & AFF_MULTI_LINE)
                        rsprintf("<br>");
                  }

                  rsprintf("</td></tr>\n");
               } else if (attr_flags[index] & AF_RADIO) {
                  /* display radio buttons */
                  rsprintf("<td class=\"attribvalue\">\n");

                  for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
                     if (strstr(attrib[index], attr_options[index][i]))
                        rsprintf
                            ("<nobr><input type=radio checked name=\"%s\" value=\"%s\">%s</nobr>\n",
                             ua, attr_options[index][i], attr_options[index][i]);
                     else
                        rsprintf
                            ("<nobr><input type=radio name=\"%s\" value=\"%s\">%s</nobr>\n",
                             ua, attr_options[index][i], attr_options[index][i]);

                     if (format_flags & AFF_MULTI_LINE)
                        rsprintf("<br>");
                  }

                  rsprintf("</td></tr>\n");
               } else if (attr_flags[index] & AF_ICON) {
                  /* display icons */
                  rsprintf("<td class=\"attribvalue\">\n");

                  for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
                     if (strstr(attrib[index], attr_options[index][i]))
                        rsprintf
                            ("<nobr><input type=radio checked name=\"%s\" value=\"%s\">",
                             ua, attr_options[index][i]);
                     else
                        rsprintf("<nobr><input type=radio name=\"%s\" value=\"%s\">",
                                 ua, attr_options[index][i]);

                     sprintf(str, "Icon comment %s", attr_options[index][i]);
                     getcfg_cond(lbs->name, condition, str, comment);

                     if (comment[0])
                        rsprintf("<img src=\"icons/%s\" alt=\"%s\"></nobr>\n",
                                 attr_options[index][i], comment);
                     else
                        rsprintf("<img src=\"icons/%s\"></nobr>\n",
                                 attr_options[index][i]);

                     if (format_flags & AFF_MULTI_LINE)
                        rsprintf("<br>");
                  }

                  rsprintf("</td></tr>\n");
               } else {

                  rsprintf("<td class=\"attribvalue\">\n");

                  sprintf(str, loc("Add %s"), attr_list[index]);
                  if (equal_ustring(getparam("extend"), str)) {

                     rsprintf("<i>");
                     rsprintf(loc("Add new option here"), attr_list[index]);
                     rsprintf("&nbsp;:&nbsp;</i>\n");

                     rsprintf
                         ("<input type=\"text\" size=20 maxlength=%d name=\"%s\" value=\"%s\">\n",
                          input_maxlen, ua, attrib[index]);


                  } else {

                     /* display drop-down box */
                     rsprintf("<select name=\"%s\"", ua);

                     if (is_cond_attr(index))
                        rsprintf(" onChange=\"document.form1.submit()\">\n");
                     else
                        rsprintf(">\n");

                     /* display emtpy option */
                     rsprintf("<option value=\"\">- %s -\n", loc("please select"));

                     for (i = 0; i < MAX_N_LIST && attr_options[index][i][0]; i++) {
                        strlcpy(str, attr_options[index][i], sizeof(str));
                        if (strchr(str, '{'))
                           *strchr(str, '{') = 0;

                        if (equal_ustring(attr_options[index][i], attrib[index])
                            || equal_ustring(str, attrib[index]))
                           rsprintf("<option selected value=\"%s\">%s\n",
                                    attr_options[index][i], str);
                        else
                           rsprintf("<option value=\"%s\">%s\n", attr_options[index][i],
                                    str);
                     }

                     rsprintf("</select>\n");

                     if (is_cond_attr(index)) {
                        /* show "update" button only of javascript is not enabled */
                        rsprintf
                            ("<script language=\"javascript\" type=\"text/javascript\">\n");
                        rsprintf("if (!navigator.javaEnabled()) {\n");
                        rsprintf
                            ("  document.write(\"<input type=submit value=\\\"%s\\\"\")\n",
                             loc("Update"));
                        rsprintf("} \n");
                        rsprintf("</script>\n");

                        rsprintf("<noscript>\n");
                        rsprintf("<input type=submit value=\"%s\">\n", loc("Update"));
                        rsprintf("</noscript>\n");
                     }

                     if (attr_flags[index] & AF_EXTENDABLE) {
                        sprintf(str, loc("Add %s"), attr_list[index]);
                        rsprintf("<input type=submit name=extend value=\"%s\">\n", str);
                     }
                  }

                  rsprintf("</td></tr>\n");
               }
            }
         }
      }
   }

   /* set textarea width */
   width = 76;

   if (getcfg_cond(lbs->name, condition, "Message width", str))
      width = atoi(str);

   /* increased width according to longest line */
   if (message_id) {
      p = text;
      do {
         pend = strchr(p, '\n');
         if (pend == NULL)
            pend = p + strlen(p);

         if ((int) pend - (int) p + 1 > width)
            width = (int) pend - (int) p + 1;

         if (*pend == 0)
            break;

         p = pend;
         while (*p && (*p == '\r' || *p == '\n'))
            p++;
      } while (1);


      /* leave space for '> ' */
      if (!bedit)
         width += 2;
   }

   /* set textarea height */
   height = 20;
   if (getcfg_cond(lbs->name, condition, "Message height", str))
      height = atoi(str);

   rsprintf("<tr><td colspan=2 class=\"attribvalue\">\n");

   if (breply)
      /* hidden text for original message */
      rsprintf("<input type=hidden name=reply_to value=\"%d\">\n", message_id);

   if (breedit || bupload)
      /* hidden text for original message */
      rsprintf("<input type=hidden name=reply_to value=\"%s\">\n", getparam("reply_to"));

   if (bedit && message_id)
      rsprintf("<input type=hidden name=edit_id value=\"%d\">\n", message_id);

   if (getcfg_cond(lbs->name, condition, "Message comment", comment)
       && !message_id) {
      rsputs(comment);
      rsputs("<br>\n");
   }

   if (!getcfg_cond(lbs->name, condition, "Show text", str)
       || atoi(str) == 1) {
      rsprintf("<textarea rows=%d cols=%d wrap=hard name=Text>", height, width);

      if (text[0]) {
         if (bedit) {
            if (bupload || (!bupload && !breedit)
                || (breedit && !getcfg_cond(lbs->name, condition, "Preset text", str)))
               rsputs(text);
         } else {
            if (!getcfg_cond(lbs->name, condition, "Quote on reply", str)
                || atoi(str) > 0) {
               if (getcfg_cond(lbs->name, condition, "Date on reply", str)
                   && atoi(str) == 1) {
                  time(&now);
                  pts = localtime(&now);
                  if (getcfg_cond(lbs->name, condition, "Date format", format))
                     strftime(str, sizeof(str), format, pts);
                  else {
                     strcpy(str, ctime(&now));
                     str[strlen(str) - 1] = 0;
                  }
                  rsprintf("%s\n\n", str);
               }

               p = text;

               if (!getcfg_cond(lbs->name, condition, "Reply string", reply_string))
                  strcpy(reply_string, "> ");

               do {
                  if (strchr(p, '\n')) {
                     *strchr(p, '\n') = 0;

                     if (encoding[0] == 'H') {
                        rsputs2(reply_string);
                        rsprintf("%s<br>\n", p);
                     } else {
                        rsputs(reply_string);
                        rsprintf("%s\n", p);
                     }

                     p += strlen(p) + 1;
                     if (*p == '\n')
                        p++;
                  } else {
                     if (encoding[0] == 'H') {
                        rsputs2(reply_string);
                        rsprintf("%s<p>\n", p);
                     } else {
                        rsputs(reply_string);
                        rsprintf("%s\n\n", p);
                     }

                     break;
                  }

               } while (TRUE);

               if (getcfg_cond(lbs->name, condition, "Date on reply", str)
                   && atoi(str) == 2) {
                  time(&now);
                  pts = localtime(&now);
                  if (getcfg_cond(lbs->name, condition, "Date format", format))
                     strftime(str, sizeof(str), format, pts);
                  else {
                     strcpy(str, ctime(&now));
                     str[strlen(str) - 1] = 0;
                  }
                  rsprintf("%s\n\n", str);
               }
            }
         }
      }

      if ((!message_id || breedit)
          && getcfg_cond(lbs->name, condition, "Preset text", str)) {
         /* check if file starts with an absolute directory */
         if (str[0] == DIR_SEPARATOR || str[1] == ':')
            strcpy(file_name, str);
         else {
            strlcpy(file_name, resource_dir, sizeof(file_name));
            strlcat(file_name, str, sizeof(file_name));
         }

         /* check if file exists */
         fh = open(file_name, O_RDONLY | O_BINARY);
         if (fh > 0) {
            length = lseek(fh, 0, SEEK_END);
            lseek(fh, 0, SEEK_SET);
            buffer = malloc(length + 1);
            read(fh, buffer, length);
            buffer[length] = 0;
            close(fh);
            rsputs(buffer);
            free(buffer);
         } else
            rsputs(str);
      }

      rsprintf("</textarea><br>\n");

      /* HTML check box */
      if (message_id) {
         if (getcfg_cond(lbs->name, condition, "HTML default", str)) {
            if (atoi(str) < 2) {
               if (encoding[0] == 'H')
                  rsprintf("<input type=checkbox checked name=html value=1>%s\n",
                           loc("Submit as HTML text"));
               else
                  rsprintf("<input type=checkbox name=html value=1>%s\n",
                           loc("Submit as HTML text"));
            } else if (atoi(str) == 3) {
               rsprintf("<input type=hidden name=html value=1>\n");
            }
         } else {
            if (encoding[0] == 'H')
               rsprintf("<input type=checkbox checked name=html value=1>%s\n",
                        loc("Submit as HTML text"));
            else
               rsprintf("<input type=checkbox name=html value=1>%s\n",
                        loc("Submit as HTML text"));
         }
      } else {
         if (getcfg_cond(lbs->name, condition, "HTML default", str)) {
            if (atoi(str) == 0) {
               rsprintf("<input type=checkbox name=html value=1>%s\n",
                        loc("Submit as HTML text"));
            } else if (atoi(str) == 1) {
               rsprintf("<input type=checkbox checked name=html value=1>%s\n",
                        loc("Submit as HTML text"));
            } else if (atoi(str) == 3) {
               rsprintf("<input type=hidden name=html value=1>\n");
            }
         } else
            rsprintf("<input type=checkbox name=html value=1>%s\n",
                     loc("Submit as HTML text"));
      }
   }

   /* Suppress email check box */
   if (!(bedit && getcfg_cond(lbs->name, condition, "Suppress Email on edit", str)
         && atoi(str) == 1)) {
      if (getcfg_cond(lbs->name, condition, "Suppress default", str)) {
         if (atoi(str) == 0) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox name=suppress value=1>%s\n",
                     loc("Suppress Email notification"));
         } else if (atoi(str) == 1) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox checked name=suppress value=1>%s\n",
                     loc("Suppress Email notification"));
         }
      } else {
         rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
         rsprintf("<input type=checkbox name=suppress value=1>%s\n",
                  loc("Suppress Email notification"));
      }
   }

   /* Suppress execute shell check box */
   if (!bedit && getcfg_cond(lbs->name, condition, "Execute new", str)) {
      if (getcfg_cond(lbs->name, condition, "Suppress execute default", str)) {
         if (atoi(str) == 0) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox name=shell_suppress value=1>%s\n",
                     loc("Suppress shell execution"));
         } else if (atoi(str) == 1) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox checked name=shell_suppress value=1>%s\n",
                     loc("Suppress shell execution"));
         }
      } else {
         rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
         rsprintf("<input type=checkbox name=shell_suppress value=1>%s\n",
                  loc("Suppress shell execution"));
      }
   }

   if (bedit && getcfg_cond(lbs->name, condition, "Execute edit", str)) {
      if (getcfg_cond(lbs->name, condition, "Suppress execute default", str)) {
         if (atoi(str) == 0) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox name=shell_suppress value=1>%s\n",
                     loc("Suppress shell execution"));
         } else if (atoi(str) == 1) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox checked name=shell_suppress value=1>%s\n",
                     loc("Suppress shell execution"));
         }
      } else {
         rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
         rsprintf("<input type=checkbox name=shell_suppress value=1>%s\n",
                  loc("Suppress shell execution"));
      }
   }

   /* Resubmit check box */
   if (bedit) {
      if (getcfg_cond(lbs->name, condition, "Resubmit default", str)) {
         if (atoi(str) == 0) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox name=resubmit value=1>%s\n",
                     loc("Resubmit as new entry"));
         } else if (atoi(str) == 1) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
            rsprintf("<input type=checkbox checked name=resubmit value=1>%s\n",
                     loc("Resubmit as new entry"));
         }
      } else {
         rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;\n");
         rsprintf("<input type=checkbox name=resubmit value=1>%s\n",
                  loc("Resubmit as new entry"));
      }
   }

   rsprintf("</tr>\n");

   if (!getcfg_cond(lbs->name, condition, "Enable attachments", str)
       || atoi(str) > 0) {
      i = 0;
      if (bedit) {
         /* show existing attachments */
         for (i = 0; i < MAX_ATTACHMENTS; i++)
            if (att[i][0]) {
               rsprintf("<tr><td nowrap class=\"attribname\">%s %d:</td>\n",
                        loc("Attachment"), i + 1);
               sprintf(str, "attachment%d", i);
               rsprintf("<td class=\"attribvalue\">\n");
               rsprintf("<input type=hidden name=\"%s\" value=\"%s\">\n", str, att[i]);
               rsprintf("%s\n", att[i] + 14);
               rsprintf
                   ("&nbsp;&nbsp;<input type=\"submit\" name=\"delatt%d\" value=\"%s\"></td></tr>\n",
                    i, loc("Delete"));
            } else
               break;
      }

      /* optional attachment comment */
      if (getcfg_cond(lbs->name, condition, "Attachment comment", comment)
          && !message_id) {
         rsprintf("<tr><td colspan=2 class=\"attribvalue\">\n");
         rsputs(comment);
         rsputs("</td></tr>\n");
      }

      /* field for add attachment */
      if (att[MAX_ATTACHMENTS - 1][0]) {
         rsprintf("<tr><td colspan=2 class=\"attribname\">%s</td>\n",
                  loc("Maximum number of attachments reached"));
         rsprintf("</td></tr>\n");
      } else {
         rsprintf("<tr><td nowrap class=\"attribname\">%s %d:</td>\n", loc("Attachment"),
                  i + 1);
         rsprintf
             ("<td class=\"attribvalue\"><input type=\"file\" size=\"60\" maxlength=\"200\" name=\"attfile\" accept=\"filetype/*\">\n");
         rsprintf("&nbsp;&nbsp;<input type=\"submit\" name=\"cmd\" value=\"%s\">\n",
                  loc("Upload"));
         rsprintf("</td></tr>\n");
      }
   }

   rsprintf("</table><!-- listframe -->\n");

   /*---- menu buttons again ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");
   rsprintf
       ("<input type=\"submit\" name=\"cmd\" value=\"%s\" onClick=\"return chkform();\">\n",
        loc("Submit"));
   rsprintf("<input type=\"submit\" name=\"cmd\" value=\"%s\">\n", loc("Back"));
   rsprintf("</span></td></tr>\n\n");

   rsprintf("</table><!-- show_standard_title -->\n");
   show_bottom_text(lbs);
   rsprintf("</form></body></html>\r\n");

   /* rescan unconditional attributes */
   if (condition[0])
      scan_attributes(lbs->name, NULL);
}

/*------------------------------------------------------------------*/

void show_find_form(LOGBOOK * lbs)
{
   int i, j;
   char str[NAME_LENGTH], mode[NAME_LENGTH], comment[NAME_LENGTH], option[NAME_LENGTH];

   /*---- header ----*/

   show_standard_header(lbs, FALSE, loc("ELOG find"), NULL);

   /*---- title ----*/

   show_standard_title(lbs->name, "", 0);

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

   rsprintf("<input type=submit value=\"%s\">\n", loc("Search"));
   rsprintf("<input type=reset value=\"%s\">\n", loc("Reset Form"));
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Back"));
   rsprintf("</span></td></tr>\n\n");

   /*---- entry form ----*/

   rsprintf("<tr><td class=\"form1\">\n");

   rsprintf("<b>%s:</b>&nbsp;&nbsp;", loc("Mode"));

   if (!getcfg(lbs->name, "Display mode", mode))
      strcpy(mode, "Full");

   if (!getcfg(lbs->name, "Show text", str) || atoi(str) == 1) {
      if (equal_ustring(mode, "Full"))
         rsprintf("<input type=radio name=mode value=\"full\" checked>%s&nbsp;&nbsp;\n",
                  loc("Display full entries"));
      else
         rsprintf("<input type=radio name=mode value=\"full\">%s&nbsp;&nbsp;\n",
                  loc("Display full entries"));

      if (equal_ustring(mode, "Summary"))
         rsprintf
             ("<input type=radio name=mode value=\"summary\" checked>%s&nbsp;&nbsp;\n",
              loc("Summary only"));
      else
         rsprintf("<input type=radio name=mode value=\"summary\">%s&nbsp;&nbsp;\n",
                  loc("Summary only"));
   } else {
      if (equal_ustring(mode, "Full") || equal_ustring(mode, "Summary"))
         rsprintf
             ("<input type=radio name=mode value=\"summary\" checked>%s&nbsp;&nbsp;\n",
              loc("Summary"));
      else
         rsprintf("<input type=radio name=mode value=\"summary\">%s&nbsp;&nbsp;\n",
                  loc("Summary"));
   }


   if (equal_ustring(mode, "Threaded"))
      rsprintf("<input type=radio name=mode value=\"threaded\" checked>%s&nbsp;&nbsp;\n",
               loc("Display threads"));
   else
      rsprintf("<input type=radio name=mode value=\"threaded\">%s&nbsp;&nbsp;\n",
               loc("Display threads"));

   if (equal_ustring(mode, "CSV"))
      rsprintf("<input type=radio name=mode value=\"CSV\" checked>%s&nbsp;&nbsp;\n",
               loc("Display comma-separated values (CSV)"));
   else
      rsprintf("<input type=radio name=mode value=\"CSV\">%s&nbsp;&nbsp;\n",
               loc("Display comma-separated values (CSV)"));

   rsprintf("</td></tr>\n");

   rsprintf("<tr><td class=\"form2\"><b>%s:</b><br>", loc("Options"));

   if (!getcfg(lbs->name, "Number attachments", str) || atoi(str) > 0)
      rsprintf("<input type=checkbox name=attach value=1>%s<br>\n",
               loc("Show attachments"));

   rsprintf("<input type=checkbox name=printable value=1>%s<br>\n",
            loc("Printable output"));

   if (getcfg(lbs->name, "Reverse sort", str) && atoi(str) == 1)
      rsprintf("<input type=checkbox checked name=reverse value=1>%s<br>\n",
               loc("Sort in reverse order"));
   else
      rsprintf("<input type=checkbox name=reverse value=1>%s<br>\n",
               loc("Sort in reverse order"));

   /* count logbooks */
   for (i = 0;; i++) {
      if (!enumgrp(i, str))
         break;

      if (is_logbook(str))
         continue;
   }

   if (i > 2) {
      if (!getcfg(lbs->name, "Search all logbooks", str) || atoi(str) == 1)
         rsprintf("<input type=checkbox name=all value=1>%s<br>\n",
                  loc("Search all logbooks"));
   }

   rsprintf(loc("Display"));
   if (!getcfg(lbs->name, "Entries per page", str))
      strcpy(str, "20");
   rsprintf(" <input type=text name=npp size=3 value=%s> ", str);
   rsprintf(loc("entries per page"));

   rsprintf("</td></tr>\n");


   rsprintf("<tr><td class=\"form2\"><b>%s:</b><br>", loc("Filters"));

   /* table for two-column items */
   rsprintf("<table width=\"100%%\" cellspacing=0>\n");

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>", loc("Start date"));
   rsprintf("<td><select name=\"m1\">\n");

   rsprintf("<option value=\"\">\n");
   for (i = 0; i < 12; i++)
      rsprintf("<option value=\"%d\">%s\n", i + 1, month_name(i));
   rsprintf("</select>\n");

   rsprintf("<select name=\"d1\">");
   rsprintf("<option selected value=\"\">\n");
   for (i = 0; i < 31; i++)
      rsprintf("<option value=%d>%d\n", i + 1, i + 1);
   rsprintf("</select>\n");

   rsprintf("&nbsp;%s: <input type=\"text\" size=5 maxlength=5 name=\"y1\">",
            loc("Year"));

   rsprintf("\n<script language=\"javascript\" type=\"text/javascript\">\n");
   rsprintf("<!--\n");
   rsprintf("function opencal(i)\n");
   rsprintf("{\n");
   rsprintf("  window.open(\"cal.html?i=\"+i, \"\",\n");
   rsprintf
       ("  \"width=300,height=195,dependent=yes,menubar=no,scrollbars=no,location=no\");\n");
   rsprintf("}\n\n");

   rsprintf("if (navigator.javaEnabled()) {\n");
   rsprintf("  document.write(\"&nbsp;&nbsp;\");\n");
   rsprintf("  document.write(\"<a href=\\\"javascript:opencal(1)\\\">\");\n");
   rsprintf
       ("  document.writeln(\"<img src=\\\"cal.gif\\\" border=\\\"0\\\" alt=\\\"%s\\\"></a>\");\n",
        loc("Pick a date"));
   rsprintf("} \n");
   rsprintf("//-->\n");
   rsprintf("</script>\n");

   rsprintf("&nbsp;&nbsp;/&nbsp;&nbsp;%s:&nbsp;", loc("Show last"));

   rsprintf("<select name=last>\n");
   rsprintf("<option value=\"\">\n");
   rsprintf("<option value=1>%s\n", loc("Day"));
   rsprintf("<option value=7>%s\n", loc("Week"));
   rsprintf("<option value=31>%s\n", loc("Month"));
   rsprintf("<option value=92>3 %s\n", loc("Months"));
   rsprintf("<option value=182>6 %s\n", loc("Months"));
   rsprintf("<option value=364>%s\n", loc("Year"));
   rsprintf("</select> \n");

   rsprintf("</td></tr>\n");

   rsprintf("<tr><td>%s:</td>", loc("End date"));
   rsprintf("<td><select name=\"m2\">\n");

   rsprintf("<option value=\"\">\n");
   for (i = 0; i < 12; i++)
      rsprintf("<option value=\"%d\">%s\n", i + 1, month_name(i));
   rsprintf("</select>\n");

   rsprintf("<select name=\"d2\">");
   rsprintf("<option selected value=\"\">\n");
   for (i = 0; i < 31; i++)
      rsprintf("<option value=%d>%d\n", i + 1, i + 1);
   rsprintf("</select>\n");

   rsprintf("&nbsp;%s: <input type=\"text\" size=5 maxlength=5 name=\"y2\">",
            loc("Year"));

   rsprintf("\n<script language=\"javascript\" type=\"text/javascript\">\n");
   rsprintf("if (navigator.javaEnabled()) {\n");
   rsprintf("  document.write(\"&nbsp;&nbsp;\");\n");
   rsprintf("  document.write(\"<a href=\\\"javascript:opencal(2)\\\">\");\n");
   rsprintf
       ("  document.writeln(\"<img src=\\\"cal.gif\\\" border=\\\"0\\\" alt=\\\"%s\\\"></a>\");\n",
        loc("Pick a date"));
   rsprintf("} \n");
   rsprintf("</script>\n");

   rsprintf("</td></tr>\n");

   for (i = 0; i < lbs->n_attr; i++) {
      rsprintf("<tr><td nowrap>%s:</td>", attr_list[i]);
      rsprintf("<td>");
      if (attr_options[i][0][0] == 0) {
         rsprintf("<input type=\"text\" size=\"30\" maxlength=\"80\" name=\"%s\">\n",
                  attr_list[i]);
         rsprintf("<i>%s</i>\n", loc("(case insensitive substring)"));
      } else {
         if (equal_ustring(attr_options[i][0], "boolean"))
            rsprintf("<input type=checkbox name=\"%s\" value=1>\n", attr_list[i]);

         /* display image for icon */
         else if (attr_flags[i] & AF_ICON) {
            for (j = 0; j < MAX_N_LIST && attr_options[i][j][0]; j++) {
               strcpy(option, attr_options[i][j]);
               if (strchr(option, '{'))
                  *strchr(option, '{') = 0;

               sprintf(str, "Icon comment %s", option);
               getcfg(lbs->name, str, comment);

               rsprintf("<nobr><input type=radio name=\"%s\" value=\"%s\">", attr_list[i],
                        option);

               if (comment[0])
                  rsprintf("<img src=\"icons/%s\" alt=\"%s\"></nobr>\n", option, comment);
               else
                  rsprintf("<img src=\"icons/%s\"></nobr>\n", option);
            }
         }

         else {
            rsprintf("<select name=\"%s\">\n", attr_list[i]);
            rsprintf("<option value=\"\">\n");
            for (j = 0; j < MAX_N_LIST && attr_options[i][j][0]; j++) {

               strcpy(option, attr_options[i][j]);
               if (strchr(option, '{'))
                  *strchr(option, '{') = 0;

               rsprintf("<option value=\"%s\">%s\n", option, option);
            }
            rsprintf("</select>\n");
         }
      }
      rsprintf("</td></tr>\n");
   }

   rsprintf("<tr><td>%s:</td>", loc("Text"));
   rsprintf("<td><input type=\"text\" size=\"30\" maxlength=\"80\" name=\"subtext\">\n");
   rsprintf("<i>%s</i></td></tr>\n", loc("(case insensitive substring)"));

   rsprintf("<tr><td><td><input type=checkbox name=sall value=1>%s</td></tr>\n",
            loc("Search text also in attributes"));

   rsprintf("</table></td></tr></table>\n");
   show_bottom_text(lbs);
   rsprintf("</form></body></html>\r\n");
}

/*------------------------------------------------------------------*/

const char *find_section(const char *buf, const char *name)
{
   const char *pstart;
   char *pstr, str[80];

   do {
      if (*buf == '[') {
         pstart = buf;
         buf++;
         pstr = str;
         while (*buf && *buf != ']' && *buf != '\n' && *buf != '\r')
            *pstr++ = *buf++;
         *pstr = 0;
         if (equal_ustring(str, name))
            return pstart;
      }

      if (buf)
         buf = strchr(buf, '\n');
      if (buf)
         buf++;
      if (buf && *buf == '\r')
         buf++;

   } while (buf);

   return NULL;
}

/*------------------------------------------------------------------*/

const char *find_next_section(const char *buf)
{
   do {
      if (*buf == '[')
         return buf;

      if (buf)
         buf = strchr(buf, '\n');
      if (buf)
         buf++;
   } while (buf);

   return NULL;
}

/*------------------------------------------------------------------*/

void load_config_section(char *section, char **buffer, char *error)
{
   int fh, length;
   char *p;

   error[0] = 0;
   *buffer = NULL;
   fh = open(config_file, O_RDONLY | O_BINARY);
   if (fh < 0) {
      sprintf(error, "Cannot read configuration file <b>\"%s\"</b>", config_file);
      return;
   }
   length = lseek(fh, 0, SEEK_END);
   lseek(fh, 0, SEEK_SET);
   *buffer = malloc(length + 1);
   if (*buffer == NULL) {
      close(fh);
      strcpy(error, "Error: out of memory");
      return;
   }
   read(fh, *buffer, length);
   (*buffer)[length] = 0;
   close(fh);

   if ((p = (char *) find_section(*buffer, section)) != NULL) {
      if (strchr(p, ']')) {
         p = strchr(p, ']') + 1;
         while (*p == ' ' || *p == '\t' || *p == '\n' || *p == '\r')
            p++;
      }
      strlcpy(*buffer, p, length);
      if ((p = (char *) find_next_section(*buffer + 1)) != NULL) {
         *p = 0;

         /* strip trailing newlines */
         if (p) {
            p--;

            while (p > *buffer && (*p == '\n' || *p == '\r' || *p == ' ' || *p == '\t'))
               *p-- = 0;
         }
      } else {
         p = *buffer + strlen(*buffer) - 1;

         while (p > *buffer && (*p == '\n' || *p == '\r' || *p == ' ' || *p == '\t'))
            *p-- = 0;
      }
   }
}

/*------------------------------------------------------------------*/

void show_admin_page(LOGBOOK * lbs, char *top_group)
{
   int rows, cols;
   char *buffer, error_str[256];
   char section[NAME_LENGTH], str[NAME_LENGTH], grp[NAME_LENGTH];

   /*---- header ----*/

   sprintf(str, "ELOG %s", loc("Admin"));
   show_html_header(lbs, FALSE, str, TRUE);

   rsprintf
       ("<body><form method=\"POST\" action=\".\" enctype=\"multipart/form-data\">\n");

   /*---- title ----*/

   show_standard_title(lbs->name, "", 0);

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Save"));
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Cancel"));

   if (lbs->top_group[0] && (!top_group || equal_ustring(top_group, "global"))) {
      if (!getcfg("global", "Admin user", str) || strstr(str, getparam("unm")) != 0) {
         if (lbs->top_group[0]) {

            sprintf(str, "global %s", lbs->top_group);

            if (is_group(str)) {
               sprintf(grp, "[global %s]", lbs->top_group);
               sprintf(str, loc("Change %s"), grp);
               rsprintf("<input type=submit name=cmd value=\"%s\">\n", str);
            }
         }
      }
   }

   if (is_group("global") && !equal_ustring(top_group, "global")) {
      if (!getcfg_simple("global", "Admin user", str)
          || strstr(str, getparam("unm")) != 0) {
         sprintf(str, loc("Change %s"), "[global]");
         rsprintf("<input type=submit name=cmd value=\"%s\">\n", str);
      }
   }

   if (top_group) {
      if (equal_ustring(top_group, "global")) {
         rsprintf("<input type=hidden name=global value=\"global\">\n");
         strcpy(str, "[global]");
      } else {
         rsprintf("<input type=hidden name=global value=\"%s\">\n", top_group);
         sprintf(str, "[global %s]", top_group);
      }
      rsprintf("<br><center><b>%s</b></center>", str);
   }

   rsprintf("</span></td></tr>\n\n");

   /*---- entry form ----*/

   rsprintf("<tr><td class=\"form1\">\n");

   /* extract section of current logbook */
   if (top_group) {
      if (equal_ustring(top_group, "global"))
         strcpy(section, "global");
      else
         sprintf(section, "global %s", top_group);
   } else
      strcpy(section, lbs->name);

   load_config_section(section, &buffer, error_str);

   if (error_str[0]) {
      rsprintf("</table></td></tr></table>\n");
      rsprintf("</body></html>\r\n");
      return;
   }

   if (getcfg(section, "Admin textarea", str)
       && strchr(str, ',') != NULL) {
      cols = atoi(str);
      rows = atoi(strchr(str, ',') + 1);
   } else {
      cols = 120;
      rows = 30;
   }

   rsprintf("<textarea cols=%d rows=%d wrap=virtual name=Text>", cols, rows);

   rsputs(buffer);
   free(buffer);

   rsprintf("</textarea>\n");

   /* put link for config page */
   rsprintf
       ("<br><a target=\"_blank\" href=\"http://midas.psi.ch/elog/config.html\">Syntax Help</a>");

   rsprintf("</td></tr>\n");

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Save"));
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Cancel"));
   rsprintf("</span></td></tr>\n\n");

   rsprintf("</table>\n\n");
   show_bottom_text(lbs);
   rsprintf("</form></body></html>\r\n");
}

/*------------------------------------------------------------------*/

void remove_crlf(char *buffer)
{
   char *p;

   p = buffer;
   while ((p = strstr(p, "\r\n")) != NULL) {
      strcpy(p, p + 1);
   }
}

/*------------------------------------------------------------------*/

int save_admin_config(LOGBOOK * lbs, char *section, char *buffer, char *error)
{
   int fh, i, length;
   char *buf, *buf2, *p1, *p2;

   error[0] = 0;

   fh = open(config_file, O_RDWR | O_BINARY, 644);
   if (fh < 0) {
      sprintf(error, loc("Cannot open file <b>%s</b>"), config_file);
      strcat(error, ": ");
      strcat(error, strerror(errno));
      return 0;
   }
#ifdef OS_UNIX

   /* under unix, convert CRLF to CR */
   remove_crlf(buffer);

#endif

   /* read previous contents */
   length = lseek(fh, 0, SEEK_END);
   lseek(fh, 0, SEEK_SET);
   buf = malloc(length + strlen(buffer) + 1);
   assert(buf);
   read(fh, buf, length);
   buf[length] = 0;

   /* find previous logbook config */
   p1 = (char *) find_section(buf, section);
   p2 = (char *) find_next_section(p1 + 1);

   /* save tail */
   if (p2) {
      buf2 = malloc(strlen(p2) + 1);
      assert(buf2);
      strlcpy(buf2, p2, strlen(p2) + 1);
   }

   /* combine old and new config */
#ifdef OS_UNIX
   sprintf(p1, "[%s]\n", section);
   strcat(p1, buffer);
   strcat(p1, "\n\n");
#else
   sprintf(p1, "[%s]\r\n", section);
   strcat(p1, buffer);
   strcat(p1, "\r\n\r\n");
#endif

   if (p2) {
      strlcat(p1, buf2, length + strlen(buffer) + 1);
      free(buf2);
   }

   lseek(fh, 0, SEEK_SET);
   i = write(fh, buf, strlen(buf));
   if (i < (int) strlen(buf)) {
      sprintf(error, loc("Cannot write to <b>%s</b>"), config_file);
      strcat(error, ": ");
      strcat(error, strerror(errno));
      close(fh);
      free(buf);
      return 0;
   }
#ifdef _MSC_VER
   chsize(fh, TELL(fh));
#else
   ftruncate(fh, TELL(fh));
#endif

   close(fh);
   free(buf);

   /* force re-read of config file */
   check_config();

   return 1;
}

/*------------------------------------------------------------------*/

int save_user_config(LOGBOOK * lbs, char *user, BOOL new_user, BOOL activate)
{
   char file_name[256], str[256], line[256], *buf, *pl, new_pwd[80], new_pwd2[80];
   char smtp_host[256], email_addr[256], mail_from[256], subject[256], mail_text[2000];
   char admin_user[80], enc_pwd[80], url[256];
   int i, fh, size, self_register;

   /* check self register flag */
   self_register = 0;
   if (getcfg(lbs->name, "Self register", str))
      self_register = atoi(str);

   if (!activate) {
      /* check for hidden password */
      if (isparam("hpwd")) {
         strcpy(new_pwd, getparam("hpwd"));
      } else {
         /* check if passwords match */
         do_crypt(getparam("newpwd"), new_pwd);
         do_crypt(getparam("newpwd2"), new_pwd2);

         if (strcmp(new_pwd, new_pwd2) != 0) {
            show_error(loc("New passwords do not match, please retype"));
            return 0;
         }
      }

      /* check if user exists */
      if (new_user && self_register == 3) {
         if (get_user_line(lbs->name, user, NULL, NULL, NULL, NULL) == 1) {
            sprintf(str, "%s \"%s\" %s", loc("Login name"), user, loc("exists already"));
            show_error(str);
            return 0;
         }
      }
   }

   if (activate || !new_user || self_register != 3) {   /* do not save in mode 3 */
      getcfg(lbs->name, "Password file", str);

      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strcpy(file_name, str);
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }

      fh = open(file_name, O_RDWR | O_BINARY | O_CREAT, 644);
      if (fh < 0) {
         sprintf(str, loc("Cannot open file <b>%s</b>"), file_name);
         show_error(str);
         return 0;
      }

      lseek(fh, 0, SEEK_END);
      size = TELL(fh);
      lseek(fh, 0, SEEK_SET);

      buf = malloc(size + 1);
      read(fh, buf, size);
      buf[size] = 0;
      pl = buf;

      while (pl < buf + size) {
         for (i = 0; pl[i] && pl[i] != '\r' && pl[i] != '\n'; i++)
            line[i] = pl[i];
         line[i] = 0;

         /* skip outcommented lines */
         if (line[0] == ';' || line[0] == '#') {
            pl += strlen(line);
            while (*pl && (*pl == '\r' || *pl == '\n'))
               pl++;
            continue;
         }

         if (line[0] == 0)
            break;

         strcpy(str, line);
         if (strchr(str, ':'))
            *strchr(str, ':') = 0;
         if (strcmp(str, user) == 0) {
            if (new_user) {
               sprintf(str, "%s \"%s\" %s", loc("Login name"), user,
                       loc("exists already"));
               show_error(str);
               free(buf);
               close(fh);
               return 0;
            }
            break;
         }

         pl += strlen(line);
         while (*pl && (*pl == '\r' || *pl == '\n'))
            pl++;
      }

      if (new_user) {
         lseek(fh, 0, SEEK_END);
         if (strlen(buf) != 0
             && (buf[strlen(buf) - 1] != '\r' && buf[strlen(buf) - 1] != '\n'))
            write(fh, "\n", 1);

         if (activate)
            sprintf(str, "%s:%s:%s:%s:%s\n", getparam("new_user_name"),
                    getparam("encpwd"), getparam("new_full_name"),
                    getparam("new_user_email"), getparam("email_notify"));
         else
            sprintf(str, "%s:%s:%s:%s:%s\n", getparam("new_user_name"),
                    new_pwd, getparam("new_full_name"), getparam("new_user_email"),
                    getparam("email_notify"));
         write(fh, str, strlen(str));
      } else {
         /* replace line */
         lseek(fh, 0, SEEK_SET);
         write(fh, buf, pl - buf);

         sprintf(str, "%s:%s:%s:%s:%s\n", getparam("new_user_name"),
                 new_pwd, getparam("new_full_name"), getparam("new_user_email"),
                 getparam("email_notify"));
         write(fh, str, strlen(str));

         pl += strlen(line);
         while (*pl && (*pl == '\r' || *pl == '\n'))
            pl++;

         write(fh, pl, strlen(pl));

#ifdef _MSC_VER
         chsize(fh, TELL(fh));
#else
         ftruncate(fh, TELL(fh));
#endif
      }

      free(buf);
      close(fh);
   }

   /* if requested, send notification email to admin user */
   if (new_user && (self_register == 2 || self_register == 3)
       && !isparam("admin")) {
      if (!getcfg("global", "SMTP host", smtp_host)) {
         show_error(loc
                    ("No SMTP host defined in [global] section of configuration file"));
         return 0;
      }

      /* try to get URL from referer */
      if (!getcfg("global", "URL", url)) {
         if (referer[0])
            strcpy(url, referer);
         else {
            if (tcp_port == 80)
               sprintf(url, "http://%s/", host_name);
            else
               sprintf(url, "http://%s:%d/", host_name, tcp_port);
         }
      } else {
         if (url[strlen(url) - 1] != '/')
            strlcat(url, "/", sizeof(url));
         if (lbs) {
            strlcat(url, lbs->name_enc, sizeof(url));
            strlcat(url, "/", sizeof(url));
         }
      }

      if (!getcfg(lbs->name, "Use Email from", mail_from))
         sprintf(mail_from, "ELog@%s", host_name);

      if (activate) {
         sprintf(subject, loc("Your ELOG account has been activated"));
         sprintf(mail_text, loc("Your ELOG account has been activated on host"));
         sprintf(mail_text + strlen(mail_text), " %s", host_name);
         sprintf(mail_text + strlen(mail_text), ".\r\n\r\n");
         sprintf(url + strlen(url), "?cmd=Login&unm=%s", getparam("new_user_name"));
         sprintf(mail_text + strlen(mail_text), "%s %s\r\n", loc("You can access it at"),
                 url);

         sendmail(lbs, smtp_host, mail_from, getparam("new_user_email"), subject,
                  mail_text, TRUE, url, NULL);
      } else {
         if (getcfg(lbs->name, "Admin user", admin_user)) {
            pl = strtok(admin_user, " ,");
            while (pl) {
               get_user_line(lbs->name, pl, NULL, NULL, email_addr, NULL);
               if (email_addr[0]) {
                  /* compose subject */
                  if (self_register == 3) {
                     if (lbs)
                        sprintf(subject, loc("Registration request on logbook \"%s\""),
                                lbs->name);
                     else
                        sprintf(subject, loc("Registration request on host \"%s\""),
                                host_name);
                     sprintf(mail_text,
                             loc("A new ELOG user wants to register on \"%s\""),
                             host_name);
                  } else {
                     if (lbs)
                        sprintf(subject, loc("User \"%s\" registered on logbook \"%s\""),
                                getparam("new_user_name"), lbs->name);
                     else
                        sprintf(subject, loc("User \"%s\" registered on host \"%s\""),
                                getparam("new_user_name"), host_name);

                     sprintf(mail_text, loc("A new ELOG user has been registered on %s"),
                             host_name);
                  }

                  sprintf(mail_text + strlen(mail_text), "\r\n\r\n");

                  if (lbs)
                     sprintf(mail_text + strlen(mail_text), "%s             : %s\r\n",
                             loc("Logbook"), lbs->name);
                  else
                     sprintf(mail_text + strlen(mail_text), "%s                : %s\r\n",
                             loc("Host"), host_name);

                  sprintf(mail_text + strlen(mail_text), "%s          : %s\r\n",
                          loc("Login name"), getparam("new_user_name"));
                  sprintf(mail_text + strlen(mail_text), "%s           : %s\r\n",
                          loc("Full name"), getparam("new_full_name"));
                  sprintf(mail_text + strlen(mail_text), "%s               : %s\r\n",
                          loc("Email"), getparam("new_user_email"));

                  if (self_register == 3) {
                     sprintf(mail_text + strlen(mail_text), "\r\n%s:\r\n",
                             loc("Hit following URL to activate that account"));

                     sprintf(mail_text + strlen(mail_text),
                             "\r\nURL                 : %s", url);

                     strcpy(str, getparam("new_full_name"));
                     url_encode(str, sizeof(str));
                     do_crypt(getparam("newpwd"), enc_pwd);
                     url_encode(enc_pwd, sizeof(enc_pwd));
                     sprintf(mail_text + strlen(mail_text),
                             "?cmd=Activate&new_user_name=%s&new_full_name=%s&new_user_email=%s&email_notify=%s&encpwd=%s&unm=%s\r\n",
                             getparam("new_user_name"), str, getparam("new_user_email"),
                             getparam("email_notify"), enc_pwd, pl);
                  } else {
                     sprintf(mail_text + strlen(mail_text),
                             "\r\n%s URL         : %s?cmd=Config&cfg_user=%s&unm=%s\r\n",
                             loc("Logbook"), url, getparam("new_user_name"), pl);
                  }

                  sendmail(lbs, smtp_host, mail_from, email_addr, subject, mail_text,
                           TRUE, url, NULL);
               }

               pl = strtok(NULL, " ,");
            }
         }

         if (self_register == 3) {
            sprintf(str, "?cmd=%s", loc("Requested"));
            redirect(lbs, str);
            return 0;
         }
      }
   }

   /* if user name changed, set cookie */
   if (strcmp(user, getparam("new_user_name")) != 0 && strcmp(user, getparam("unm")) == 0) {
      set_login_cookies(lbs, getparam("new_user_name"), new_pwd);
      return 0;
   }

   /* if new user, login as this user */
   if (new_user && !*getparam("unm")) {
      set_login_cookies(lbs, getparam("new_user_name"), new_pwd);
      return 0;
   }

   return 1;
}

/*------------------------------------------------------------------*/

int remove_user(LOGBOOK * lbs, char *user)
{
   char file_name[256], str[256], line[256], *buf, *pl;
   int i, fh, size;

   getcfg(lbs->name, "Password file", str);

   if (str[0] == DIR_SEPARATOR || str[1] == ':')
      strcpy(file_name, str);
   else {
      strlcpy(file_name, resource_dir, sizeof(file_name));
      strlcat(file_name, str, sizeof(file_name));
   }

   fh = open(file_name, O_RDWR | O_BINARY, 0644);
   if (fh < 0) {
      sprintf(str, loc("Cannot open file <b>%s</b>"), file_name);
      strcat(str, ": ");
      strcat(str, strerror(errno));
      show_error(str);
      return 0;
   }

   lseek(fh, 0, SEEK_END);
   size = TELL(fh);
   lseek(fh, 0, SEEK_SET);

   buf = malloc(size + 1);
   read(fh, buf, size);
   buf[size] = 0;
   pl = buf;

   while (pl < buf + size) {
      for (i = 0; pl[i] && pl[i] != '\r' && pl[i] != '\n'; i++)
         line[i] = pl[i];
      line[i] = 0;

      if (line[0] == ';' || line[0] == '#' || line[0] == 0) {
         pl += strlen(line);
         while (*pl && (*pl == '\r' || *pl == '\n'))
            pl++;
         continue;
      }

      strcpy(str, line);
      if (strchr(str, ':'))
         *strchr(str, ':') = 0;
      if (strcmp(str, user) == 0)
         break;

      pl += strlen(line);
      while (*pl && (*pl == '\r' || *pl == '\n'))
         pl++;
   }

   /* remove line */
   lseek(fh, 0, SEEK_SET);
   write(fh, buf, pl - buf);

   pl += strlen(line);
   while (*pl && (*pl == '\r' || *pl == '\n'))
      pl++;

   write(fh, pl, strlen(pl));

#ifdef _MSC_VER
   chsize(fh, TELL(fh));
#else
   ftruncate(fh, TELL(fh));
#endif

   free(buf);
   close(fh);

   return 1;
}

/*------------------------------------------------------------------*/

int ascii_compare(const void *s1, const void *s2)
{
   return stricmp(*(char **) s1, *(char **) s2);
}

/*------------------------------------------------------------------*/

void show_config_page(LOGBOOK * lbs)
{
   char str[256], user[80], password[80], full_name[80], user_email[80],
       email_notify[256], logbook[256];
   char **user_list;
   int i, n;

   if (lbs)
      strcpy(logbook, lbs->name);
   else
      strcpy(logbook, "global");

   /*---- header ----*/

   show_standard_header(lbs, TRUE, loc("ELOG user config"), ".");

   /*---- title ----*/

   show_standard_title(logbook, "", 0);

   /* get user */
   strcpy(user, getparam("unm"));
   if (isparam("cfg_user"))
      strcpy(user, getparam("cfg_user"));

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

   rsprintf("<input type=hidden name=cmd value=\"%s\">\n", loc("Config"));      // for select javascript
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Save"));
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Back"));
   rsprintf("<input type=hidden name=config value=\"%s\">\n", user);

   rsprintf("</span></td></tr>\n\n");

   /* table for two-column items */
   rsprintf("<tr><td class=\"form2\">");
   rsprintf("<table width=\"100%%\" cellspacing=0>\n");

   /*---- if admin user, show user list ----*/

   if (getcfg(logbook, "Admin user", str) && strstr(str, getparam("unm")) != 0) {
      rsprintf("<input type=hidden name=admin value=1>\n");
      rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Select user"));
      rsprintf("<td><select name=cfg_user onChange=\"document.form1.submit()\">\n");

      /* count user list */
      for (n = 0;; n++) {
         if (!enum_user_line(lbs, n, str))
            break;
      }

      /* allocate list of users and populate it */
      user_list = calloc(sizeof(char *), n);
      for (i = 0; i < n; i++)
         user_list[i] = calloc(NAME_LENGTH, 1);

      for (i = 0; i < n; i++)
         enum_user_line(lbs, i, user_list[i]);

      /* sort list */
      qsort(user_list, n, sizeof(char *), ascii_compare);

      for (i = 0; i < n; i++) {
         if (strcmp(user_list[i], user) == 0)
            rsprintf("<option selected value=\"%s\">%s\n", user_list[i], user_list[i]);
         else
            rsprintf("<option value=\"%s\">%s\n", user_list[i], user_list[i]);
      }

      for (i = 0; i < n; i++)
         free(user_list[i]);
      free(user_list);

      rsprintf("</select>\n");

      /* show "update" button only of javascript is not enabled */
      rsprintf("<script language=\"javascript\" type=\"text/javascript\">\n");
      rsprintf("if (!navigator.javaEnabled()) {\n");
      rsprintf("  document.write(\"<input type=submit value=\\\"%s\\\"\")\n",
               loc("Update"));
      rsprintf("} \n");
      rsprintf("</script>\n");

      rsprintf("<noscript>\n");
      rsprintf("<input type=submit value=\\\"%s\\\">\n", loc("Update"));
      rsprintf("</noscript>\n");
   }

   /*---- entry form ----*/

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Login name"));

   if (get_user_line(logbook, user, password, full_name, user_email, email_notify) != 1)
      sprintf(str, loc("User [%s] has been deleted"), user);
   else
      strcpy(str, user);

   rsprintf("<td><input type=text size=40 name=new_user_name value=\"%s\"></td></tr>\n",
            str);

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Full name"));
   rsprintf("<td><input type=text size=40 name=new_full_name value=\"%s\"></tr>\n",
            full_name);

   rsprintf("<tr><td nowrap width=\"10%%\">Email:</td>\n");
   rsprintf
       ("<td><input type=text size=40 name=new_user_email value=\"%s\">&nbsp;&nbsp;&nbsp;&nbsp;\n",
        user_email);

   rsprintf("%s:\n", loc("Enable email notifications"));

   if (email_notify[0])
      rsprintf("<input type=checkbox checked name=email_notify value=all></td></tr>\n");
   else
      rsprintf("<input type=checkbox name=email_notify value=all></td></tr>\n");

   rsprintf("</table></td></tr>\n");

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Change password"));
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Remove user"));

   if (!getcfg(logbook, "Admin user", str) || (getcfg(logbook, "Admin user", str)
                                               && strstr(str, getparam("unm")) != 0)) {
      rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("New user"));
      rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Change elogd.cfg"));
   }

   /* hidden field for password */
   rsprintf("<input type=hidden name=hpwd value=\"%s\">\n", password);

   rsprintf("</span></td></tr></table>\n\n");
   show_bottom_text(lbs);
   rsprintf("</form></body></html>\r\n");
}

/*------------------------------------------------------------------*/

void show_forgot_pwd_page(LOGBOOK * lbs)
{
   int i;
   char str[1000], login_name[256], full_name[256], user_email[256],
       name[256], pwd[256], redir[256], pwd_encrypted[256], smtp_host[256],
       mail_from[256], subject[256], mail_text[1000], url[1000];

   if (isparam("login_name")) {
      /* seach in pwd file */

      strcpy(name, getparam("login_name"));

      for (i = 0;; i++) {
         if (!enum_user_line(lbs, i, login_name))
            break;

         get_user_line(lbs->name, login_name, NULL, full_name, user_email, NULL);

         if (equal_ustring(name, login_name)
             || equal_ustring(name, full_name)
             || equal_ustring(name, user_email)) {
            if (user_email[0] == 0) {
               sprintf(str,
                       loc("No Email address registered with user name <i>\"%s\"</i>"),
                       name);
               show_error(str);
               return;
            }

            /* create random password */
            srand((unsigned int) time(NULL));
            for (i = 0; i < 6; i++)
               str[i] = rand() & 0x7F;
            str[i] = 0;
            base64_encode(str, pwd);
            do_crypt(pwd, pwd_encrypted);

            /* send email with new password */
            if (!getcfg("global", "SMTP host", smtp_host)) {
               show_error(loc
                          ("No SMTP host defined in [global] section of configuration file"));
               return;
            }

            /* try to get URL from referer */
            if (!getcfg("global", "URL", url)) {
               if (referer[0])
                  strcpy(url, referer);
               else {
                  if (tcp_port == 80)
                     sprintf(url, "http://%s/", host_name);
                  else
                     sprintf(url, "http://%s:%d/", host_name, tcp_port);
               }
            } else {
               if (url[strlen(url) - 1] != '/')
                  strlcat(url, "/", sizeof(url));
               if (lbs) {
                  strlcat(url, lbs->name_enc, sizeof(url));
                  strlcat(url, "/", sizeof(url));
               }
            }

            sprintf(redir, "?cmd=%s&old_pwd=%s", loc("Change password"), pwd);
            url_encode(redir, sizeof(redir));
            sprintf(str, "?redir=%s&uname=%s&upassword=%s", redir, login_name, pwd);
            strlcat(url, str, sizeof(url));

            if (!getcfg(lbs->name, "Use Email from", mail_from))
               sprintf(mail_from, "ELog@%s", host_name);

            if (lbs)
               sprintf(subject, loc("Password recovery for ELOG %s"), lbs->name);
            else
               sprintf(subject, loc("Password recovery for ELOG %s"), host_name);

            sprintf(mail_text, loc("A new password has been created for you on host %s"),
                    host_name);
            strlcat(mail_text, ".\r\n", sizeof(mail_text));
            strlcat(mail_text,
                    loc
                    ("Please log on by clicking on following link and change your password"),
                    sizeof(mail_text));
            strlcat(mail_text, ":\r\n\r\n", sizeof(mail_text));
            strlcat(mail_text, url, sizeof(mail_text));
            strlcat(mail_text, "\r\n\r\n", sizeof(mail_text));
            sprintf(mail_text + strlen(mail_text), "ELOG Version %s\r\n", VERSION);

            if (sendmail
                (lbs, smtp_host, mail_from, user_email, subject, mail_text, TRUE, url,
                 NULL) != -1) {
               /* save new password */
               change_pwd(lbs, login_name, pwd_encrypted);

               /* show notification web page */
               show_standard_header(lbs, FALSE, loc("ELOG password recovery"), "");

               rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");
               rsprintf("<tr><td colspan=2 class=\"dlgtitle\">\n");

               rsprintf(loc("A new password for user <i>\"%s\"</i> has been sent to %s"),
                        full_name, user_email);

               rsprintf("</td></tr></table>\n");
               show_bottom_text(lbs);
               rsprintf("</body></html>\n");
               return;
            } else {
               sprintf(str, loc("Error sending Email via <i>\"%s\"</i>"), smtp_host);
               show_error(str);
               return;
            }
         }
      }

      if (strchr(name, '@'))
         sprintf(str, loc("Email address <i>\"%s\"</i> not registered"), name);
      else
         sprintf(str, loc("User name <i>\"%s\"</i> not registered"), name);

      show_error(str);

      return;
   } else {
      /*---- header ----*/

      show_standard_header(lbs, TRUE, loc("ELOG password recovery"), NULL);

      rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");

      /*---- entry form ----*/

      rsprintf("<tr><td class=\"dlgtitle\">%s</td></tr>\n",
               loc("Enter your user name or email address"));


      rsprintf("<tr><td align=center class=\"dlgform\">\n");
      rsprintf("<input type=hidden name=cmd value=%s>\n", loc("Forgot"));
      rsprintf("<input type=text size=40 name=login_name></td></tr>\n");

      rsprintf
          ("<tr><td align=center class=\"dlgform\"><input type=submit value=\"%s\">\n",
           loc("Submit"));

      rsprintf("</td></tr></table>\n\n");
      show_bottom_text(lbs);
      rsprintf("</body></html>\r\n");
   }
}


/*------------------------------------------------------------------*/

void show_new_user_page(LOGBOOK * lbs)
{
   /*---- header ----*/

   show_standard_header(lbs, TRUE, loc("ELOG new user"), "");

   /*---- title ----*/

   if (lbs)
      show_standard_title(lbs->name, "", 1);
   else
      show_standard_title("ELOG", "", 1);

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Save"));
   rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Cancel"));
   rsprintf("</span></td></tr>\n\n");

   /* table for two-column items */
   rsprintf("<tr><td class=\"form2\">");
   rsprintf("<table width=\"100%%\" cellspacing=0>\n");

   /*---- entry form ----*/

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Login name"));
   rsprintf
       ("<td><input type=text size=40 name=new_user_name></td><td align=left><i><font size=2>(%s)</i></font></td></tr>\n",
        loc("name may not contain blanks"));

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Full name"));
   rsprintf("<td colspan=2><input type=text size=40 name=new_full_name></tr>\n");

   rsprintf("<tr><td nowrap width=\"10%%\">Email:</td>\n");
   rsprintf("<td colspan=2><input type=text size=40 name=new_user_email></tr>\n");

   rsprintf("<tr><td colspan=3>%s:&nbsp;\n", loc("Enable email notifications"));
   rsprintf("<input type=checkbox checked name=email_notify value=all></tr>\n");

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Password"));
   rsprintf("<td colspan=2><input type=password size=40 name=newpwd>\n");

   rsprintf("<tr><td nowrap width=\"10%%\">%s:</td>\n", loc("Retype password"));
   rsprintf("<td colspan=2><input type=password size=40 name=newpwd2>\n");

   rsprintf("</td></tr></table></td></tr>\n");

   rsprintf("</td></tr></table>\n\n");
   show_bottom_text(lbs);
   rsprintf("</body></html>\r\n");
}

/*------------------------------------------------------------------*/

void show_elog_delete(LOGBOOK * lbs, int message_id)
{
   int i, status, reply, next;
   char str[256], in_reply_to[80], reply_to[MAX_REPLY_TO * 10], owner[256];
   char attrib[MAX_N_ATTR][NAME_LENGTH];

   /* redirect if confirm = NO */
   if (getparam("confirm") && *getparam("confirm")
       && strcmp(getparam("confirm"), loc("No")) == 0) {
      if (message_id) {
         sprintf(str, "%d", message_id);
         redirect(lbs, str);
      } else {
         strlcpy(str, getparam("lastcmd"), sizeof(str));
         url_decode(str);
         redirect(lbs, str);
      }
      return;
   }

   if (getparam("confirm") && *getparam("confirm")) {
      if (strcmp(getparam("confirm"), loc("Yes")) == 0) {
         if (message_id) {
            /* delete message */
            status = el_delete_message(lbs, message_id, TRUE, NULL, TRUE, TRUE);
            if (status != EL_SUCCESS) {
               sprintf(str, "%s = %d", loc("Error deleting message: status"), status);
               show_error(str);
               return;
            } else {
               strcpy(str, getparam("nextmsg"));
               if (atoi(str) == 0)
                  sprintf(str, "%d", el_search_message(lbs, EL_LAST, 0, TRUE));
               if (atoi(str) == 0)
                  redirect(lbs, "");
               else
                  redirect(lbs, str);
               return;
            }
         } else {
            for (i = reply = 0; i < atoi(getparam("nsel")); i++) {
               sprintf(str, "s%d", i);
               if (isparam(str))
                  status =
                      el_delete_message(lbs, atoi(getparam(str)), TRUE, NULL, TRUE, TRUE);
            }

            redirect(lbs, getparam("lastcmd"));
            return;
         }
      }
   } else {
      /* check if at least one message is selected */
      if (!message_id) {
         for (i = 0; i < atoi(getparam("nsel")); i++) {
            sprintf(str, "s%d", i);
            if (isparam(str))
               break;
         }
         if (i == atoi(getparam("nsel"))) {
            show_error(loc("No entry selected for deletion"));
            return;
         }
      }

      /* check for author */
      if (getcfg(lbs->name, "Restrict edit", str) && atoi(str) == 1) {
         /* get message for reply/edit */

         el_retrieve(lbs, message_id, NULL, attr_list, attrib, lbs->n_attr, NULL, NULL,
                     NULL, NULL, NULL, NULL, NULL);

         if (!is_author(lbs, attrib, owner)) {
            sprintf(str, loc("Only user <i>%s</i> can delete this entry"), owner);
            show_error(str);
            return;
         }
      }

      /* header */
      if (message_id)
         sprintf(str, "%d", message_id);
      else
         str[0] = 0;
      show_standard_header(lbs, TRUE, "Delete ELog entry", str);

      rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");
      rsprintf("<tr><td class=\"dlgtitle\">\n");

      /* define hidden field for command */
      rsprintf("<input type=hidden name=cmd value=\"%s\">\n", loc("Delete"));

      if (!message_id) {
         rsprintf("%s</td></tr>\n", loc("Are you sure to delete these messages?"));

         rsprintf("<tr><td align=center class=\"dlgform\">\n");
         rsprintf("<input type=hidden name=nsel value=%s>\n", getparam("nsel"));

         if (isparam("lastcmd")) {
            strcpy(str, getparam("lastcmd"));
            rsprintf("<input type=hidden name=lastcmd value=\"%s\">\n", str);
         }

         for (i = reply = 0; i < atoi(getparam("nsel")); i++) {
            sprintf(str, "s%d", i);
            if (isparam(str)) {
               rsprintf("#%s ", getparam(str));
               rsprintf("<input type=hidden name=%s value=%s>\n", str, getparam(str));
            }

            if (!reply) {
               el_retrieve(lbs, atoi(getparam(str)), NULL, attr_list, NULL, 0, NULL, NULL,
                           in_reply_to, reply_to, NULL, NULL, NULL);
               if (reply_to[0])
                  reply = TRUE;
            }
         }

         rsprintf("</td></tr>\n");

         if (reply)
            rsprintf("<tr><td align=center class=\"dlgform\">%s</td></tr>\n",
                     loc("and all their replies"));

      } else {
         rsprintf("%s</td></tr>\n", loc("Are you sure to delete this message?"));

         /* check for replies */

         /* retrieve original message */
         el_retrieve(lbs, message_id, NULL, attr_list, NULL, 0, NULL, NULL, in_reply_to,
                     reply_to, NULL, NULL, NULL);

         if (reply_to[0])
            rsprintf("<tr><td align=center class=\"dlgform\">#%d<br>%s</td></tr>\n",
                     message_id, loc("and all its replies"));
         else
            rsprintf("<tr><td align=center class=\"dlgform\">#%d</td></tr>\n",
                     message_id);

         /* put link to next message */
         next = el_search_message(lbs, EL_NEXT, message_id, TRUE);

         rsprintf("<input type=hidden name=nextmsg value=%d>\n", next);
      }

      rsprintf
          ("<tr><td align=center class=\"dlgform\"><input type=submit name=confirm value=\"%s\">\n",
           loc("Yes"));
      rsprintf("<input type=submit name=confirm value=\"%s\">\n", loc("No"));
      rsprintf("</td></tr>\n\n");
   }

   rsprintf("</table>\n");
   show_bottom_text(lbs);
   rsprintf("</body></html>\r\n");
}

/*------------------------------------------------------------------*/

int show_download_page(LOGBOOK * lbs, char *path)
{
   char file_name[256], error_str[256];
   int index, message_id, fh, i, size, delta;
   char message[TEXT_SIZE + 1000], *p, *buffer;

   message_id = atoi(path);

   if (message_id == 0) {

      /* return config */
      load_config_section(lbs->name, &buffer, error_str);
      if (error_str[0]) {
         rsprintf("Error loading configuration file: %s", error_str);
         return EL_FILE_ERROR;
      }

      size = strlen(buffer);
      strlcpy(message, buffer, sizeof(message));
      free(buffer);

   } else {

      /* return entry */

      for (index = 0; index < *lbs->n_el_index; index++)
         if (lbs->el_index[index].message_id == message_id)
            break;

      if (index == *lbs->n_el_index)
         return EL_NO_MSG;

      sprintf(file_name, "%s%s", lbs->data_dir, lbs->el_index[index].file_name);
      fh = open(file_name, O_RDWR | O_BINARY, 0644);
      if (fh < 0)
         return EL_FILE_ERROR;

      lseek(fh, lbs->el_index[index].offset, SEEK_SET);
      i = read(fh, message, sizeof(message) - 1);
      if (i <= 0) {
         close(fh);
         return EL_FILE_ERROR;
      }

      message[i] = 0;
      close(fh);

      /* decode message size */
      p = strstr(message + 8, "$@MID@$:");
      if (p == NULL)
         size = strlen(message);
      else
         size = (int) p - (int) message;

      message[size] = 0;
   }

   show_plain_header(size);

   /* increase return buffer size if file too big */
   if (size > return_buffer_size - (int) strlen(return_buffer)) {
      delta = size - (return_buffer_size - strlen(return_buffer)) + 1000;

      return_buffer = realloc(return_buffer, return_buffer_size + delta);
      memset(return_buffer + return_buffer_size, 0, delta);
      return_buffer_size += delta;
   }

   return_length = strlen(return_buffer) + size;
   strlcat(return_buffer, message, return_buffer_size);

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

int show_md5_page(LOGBOOK * lbs)
{
   int i, j;
   char *buffer, error_str[256];
   unsigned char digest[16];

   /* header */
   rsprintf("HTTP/1.1 200 Document follows\r\n");
   rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
   rsprintf("Accept-Ranges: bytes\r\n");
   rsprintf("Connection: close\r\n");
   rsprintf("Content-Type: text/plain;charset=iso-8859-1\r\n");
   rsprintf("Pragma: no-cache\r\n");
   rsprintf("Expires: Fri, 01 Jan 1983 00:00:00 GMT\r\n\r\n");

   /* calculate MD5 for logbook section in config file */
   load_config_section(lbs->name, &buffer, error_str);
   if (error_str[0])
      rsprintf("Error loading configuration file: %s", error_str);
   else {
      rsprintf("ID: %6d MD5:", 0);

      MD5_checksum(buffer, strlen(buffer), digest);

      for (i = 0; i < 16; i++)
         rsprintf("%02X", digest[i]);
      rsprintf("\n");
   }
   free(buffer);

   /* show MD5's of logbook entries */
   for (i = 0; i < *lbs->n_el_index; i++) {
      rsprintf("ID: %6d MD5:", lbs->el_index[i].message_id);
      for (j = 0; j < 16; j++)
         rsprintf("%02X", lbs->el_index[i].md5_digest[j]);
      rsprintf("\n");
   }

   keep_alive = 0;

   return EL_SUCCESS;
}

/*------------------------------------------------------------------*/

void combine_url(LOGBOOK * lbs, char *url, char *param, char *result, int size)
{

   if (strstr(url, "http://"))
      strlcpy(result, url + 7, size);
   else
      strlcpy(result, url, size);

   url_encode(result, size);

   if (result[strlen(result) - 1] != '/')
      strlcat(result, "/", size);

   if (!strstr(result, lbs->name_enc)) {
      strlcat(result, lbs->name_enc, size);
      strlcat(result, "/", size);
   }

   if (param)
      strlcat(result, param, size);
}

/*------------------------------------------------------------------*/

int retrieve_remote_md5(LOGBOOK * lbs, char *host, MD5_INDEX ** md5_index,
                        char *error_str)
{
   int i, n, id, x, version;
   char *text, *p, url[256], str[256];

   *md5_index = NULL;

   combine_url(lbs, host, "?cmd=GetMD5", url, sizeof(url));

   text = NULL;
   error_str[0] = 0;
   if (retrieve_url(url, &text) < 0) {
      sprintf(error_str, loc("Cannot connect to remote server \"%s\""), host);
      return -1;
   }
   p = strstr(text, "ELOG HTTP ");
   if (!p) {
      sprintf(error_str, loc("Remote server is not an ELOG server"));
      free(text);
      return -1;
   }
   version = atoi(p + 10) * 100 + atoi(p + 12) * 10 + atoi(p + 14);
   if (version < 250) {
      memset(str, 0, sizeof(str));
      strncpy(str, p + 10, 5);
      sprintf(error_str, loc("Incorrect remote ELOG server version %s"), str);
      free(text);
      return -1;
   }

   p = strstr(text, "Location: ");
   if (p) {
      if (strstr(text, "?wusr="))
         sprintf(error_str, loc("User \"%s\" has no access to remote logbook"),
                 getparam("unm"));
      else if (strstr(text, "?wpwd="))
         sprintf(error_str,
                 loc("Passwords for user \"%s\" do not match locally and remotely"),
                 getparam("unm"));
      else
         sprintf(error_str, loc("Error accessing remote logbook"));

      return -1;
   }

   p = strstr(text, "\r\n\r\n");
   if (!p) {
      sprintf(error_str, loc("Invalid HTTP header"));
      free(text);
      return -1;
   }

   for (n = 0;; n++) {
      p = strstr(p, "ID:");
      if (!p)
         break;
      p += 3;

      id = atoi(p);

      p = strstr(p, "MD5:");
      if (!p)
         break;
      p += 4;

      if (n == 0)
         *md5_index = malloc(sizeof(MD5_INDEX));
      else
         *md5_index = realloc(*md5_index, (n + 1) * sizeof(MD5_INDEX));

      (*md5_index)[n].message_id = id;

      for (i = 0; i < 16; i++) {
         sscanf(p + 2 * i, "%02X", &x);
         (*md5_index)[n].md5_digest[i] = (unsigned char) x;
      }
   }

   if (n == 0) {
      if (strstr(text, "Login"))
         sprintf(error_str, loc("No user name supplied to access remote logbook"));
      else
         sprintf(error_str, loc("Error accessing remote logbook"));
   }

   free(text);

   return n;
}

/*------------------------------------------------------------------*/

INT send_tcp(int sock, char *buffer, unsigned int buffer_size, INT flags)
/********************************************************************\
  
    Send network data over TCP port. Break buffer in smaller
    parts if larger than maximum TCP buffer size (usually 64k).

\********************************************************************/
{
#ifndef NET_TCP_SIZE
#define NET_TCP_SIZE 65536
#endif

   unsigned int count;
   int status;

   /* transfer fragments until complete buffer is transferred */

   for (count = 0; count < buffer_size - NET_TCP_SIZE;) {
      status = send(sock, buffer + count, NET_TCP_SIZE, flags);
      if (status != -1)
         count += status;
      else {
         return status;
      }
   }

   while (count < buffer_size) {
      status = send(sock, buffer + count, buffer_size - count, flags);
      if (status != -1)
         count += status;
      else {
         return status;
      }
   }

   return count;
}

/*------------------------------------------------------------------*/

int submit_message(LOGBOOK * lbs, char *host, int message_id, char *error_str)
{
   int size, i, n, status, fh, port, sock, content_length, header_length, remote_id,
       n_attr;
   char str[256], file_name[MAX_PATH_LENGTH], attrib[MAX_N_ATTR][NAME_LENGTH];
   char host_name[256], subdir[256], param[256], local_host_name[256], url[256];
   char date[80], *text, in_reply_to[80], reply_to[MAX_REPLY_TO * 10],
       attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH], encoding[80], locked_by[256],
       *buffer;
   char *content, *p, boundary[80], request[10000], response[10000];
   struct hostent *phe;
   struct sockaddr_in bind_addr;

   text = malloc(TEXT_SIZE);
   error_str[0] = 0;

   /* get message with attribute list devied from database */
   size = TEXT_SIZE;
   status =
       el_retrieve(lbs, message_id, date, attr_list, attrib, -1,
                   text, &size, in_reply_to, reply_to, attachment, encoding, locked_by);

   if (status != EL_SUCCESS) {
      free(text);
      strcpy(error_str, loc("Cannot read entry from local logbook"));
      return -1;
   }

   /* count attributes */
   for (n_attr = 0; attr_list[n_attr][0]; n_attr++);

   combine_url(lbs, host, "", url, sizeof(url));
   split_url(url, host_name, &port, subdir, param);

   /* create socket */
   if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      free(text);
      strcpy(error_str, loc("Cannot create socket"));
      return -1;
   }

   /* get local host name */
   gethostname(local_host_name, sizeof(local_host_name));

   /* compose remote address */
   memset(&bind_addr, 0, sizeof(bind_addr));
   bind_addr.sin_family = AF_INET;
   bind_addr.sin_addr.s_addr = 0;
   bind_addr.sin_port = htons((unsigned short) port);

   phe = gethostbyname(host_name);
   if (phe == NULL) {
      closesocket(sock);
      free(text);
      sprintf(error_str, loc("Cannot resolve host name \"%s\""), host_name);
      return -1;
   }
   memcpy((char *) &(bind_addr.sin_addr), phe->h_addr, phe->h_length);

   /* connect to server */
   status = connect(sock, (void *) &bind_addr, sizeof(bind_addr));
   if (status != 0) {
      closesocket(sock);
      free(text);
      sprintf(error_str, loc("Cannot connect to host %s, port %d"), host_name, port);
      return -1;
   }

   content_length = 100000;
   for (i = 0; i < MAX_ATTACHMENTS; i++)
      if (attachment[i][0]) {
         strlcpy(file_name, lbs->data_dir, sizeof(file_name));
         strlcat(file_name, attachment[i], sizeof(file_name));

         fh = open(file_name, O_RDONLY | O_BINARY);
         if (fh > 0) {
            lseek(fh, 0, SEEK_END);
            size = TELL(fh);
            close(fh);
         } else
            size = 0;

         content_length += size;
      }

   content = malloc(content_length);
   if (content == NULL) {
      closesocket(sock);
      free(text);
      strcpy(error_str, loc("Not enough memory"));
      return -1;
   }

   /* compose content */
   srand((unsigned) time(NULL));
   sprintf(boundary, "---------------------------%04X%04X%04X", rand(), rand(), rand());
   strcpy(content, boundary);
   strcat(content, "\r\nContent-Disposition: form-data; name=\"cmd\"\r\n\r\nSubmit\r\n");

   sprintf(content + strlen(content),
           "%s\r\nContent-Disposition: form-data; name=\"mirror_id\"\r\n\r\n%d\r\n",
           boundary, message_id);

   if (isparam("unm"))
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"unm\"\r\n\r\n%s\r\n",
              boundary, getparam("unm"));

   if (isparam("upwd"))
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"upwd\"\r\n\r\n%s\r\n",
              boundary, getparam("upwd"));

   if (in_reply_to[0])
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"in_reply_to\"\r\n\r\n%s\r\n",
              boundary, in_reply_to);

   if (reply_to[0])
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"reply_to\"\r\n\r\n%s\r\n",
              boundary, reply_to);

   for (i = 0; i < n_attr; i++)
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"%s\"\r\n\r\n%s\r\n", boundary,
              attr_list[i], attrib[i]);

   sprintf(content + strlen(content),
           "%s\r\nContent-Disposition: form-data; name=\"entry_date\"\r\n\r\n%s\r\n",
           boundary, date);

   sprintf(content + strlen(content),
           "%s\r\nContent-Disposition: form-data; name=\"encoding\"\r\n\r\n%s\r\n",
           boundary, encoding);

   sprintf(content + strlen(content),
           "%s\r\nContent-Disposition: form-data; name=\"Text\"\r\n\r\n%s\r\n%s\r\n",
           boundary, text, boundary);

   content_length = strlen(content);
   p = content + content_length;

   /* read attachments */
   for (i = 0; i < MAX_ATTACHMENTS; i++)
      if (attachment[i][0]) {
         strlcpy(file_name, lbs->data_dir, sizeof(file_name));
         strlcat(file_name, attachment[i], sizeof(file_name));

         fh = open(file_name, O_RDONLY | O_BINARY);
         if (fh > 0) {
            lseek(fh, 0, SEEK_END);
            size = TELL(fh);
            lseek(fh, 0, SEEK_SET);

            buffer = malloc(size);

            if (buffer == NULL) {
               closesocket(sock);
               free(text);
               strcpy(error_str, loc("Not enough memory"));
               return -1;
            }

            read(fh, buffer, size);

            close(fh);

            /* submit attachment */
            sprintf(p,
                    "Content-Disposition: form-data; name=\"attfile%d\"; filename=\"%s\"\r\n\r\n",
                    i + 1, attachment[i]);

            content_length += strlen(p);
            p += strlen(p);

            memcpy(p, buffer, size);
            p += size;
            strcpy(p, boundary);
            strcat(p, "\r\n");

            content_length += size + strlen(p);
            p += strlen(p);

            free(buffer);
         }
      }

   /* compose request */
   strcpy(request, "POST ");
   if (subdir[0]) {
      if (subdir[0] != '/')
         strcat(request, "/");
      strcat(request, subdir);
      if (request[strlen(request) - 1] != '/')
         strcat(request, "/");
   }
   strcat(request, " HTTP/1.0\r\n");

   sprintf(request + strlen(request),
           "Content-Type: multipart/form-data; boundary=%s\r\n", boundary);
   sprintf(request + strlen(request), "Host: %s\r\n", local_host_name);
   sprintf(request + strlen(request), "User-Agent: ELOGD\r\n");
   sprintf(request + strlen(request), "Content-Length: %d\r\n", content_length);

   if (isparam("wpwd"))
      sprintf(request + strlen(request), "Cookie: wpwd=%s\r\n", getparam("wpwd"));

   strcat(request, "\r\n");

   header_length = strlen(request);

   /* send request */
   send(sock, request, header_length, 0);

   /* send content */
   send_tcp(sock, content, content_length, 0);

   /* receive response */
   i = recv(sock, response, 10000, 0);
   if (i < 0) {
      closesocket(sock);
      free(text);
      strcpy(error_str, "Cannot receive response");
      return -1;
   }

   /* discard remainder of response */
   n = i;
   while (i > 0) {
      i = recv(sock, response + n, 10000, 0);
      if (i > 0)
         n += i;
   }
   response[n] = 0;

   closesocket(sock);
   remote_id = -1;

   /* check response status */
   if (strstr(response, "302 Found")) {
      if (strstr(response, "Location:")) {
         if (strstr(response, "wpwd"))
            sprintf(error_str, "Invalid password\n");
         else if (strstr(response, "wusr"))
            sprintf(error_str, "Invalid user name\n");

         strlcpy(str, strstr(response, "Location:") + 9, sizeof(str));
         if (strchr(str, '\n'))
            *strchr(str, '\n') = 0;
         if (strchr(str, '?'))
            *strchr(str, '?') = 0;

         if (strrchr(str, '/'))
            remote_id = atoi(strrchr(str, '/') + 1);
         else
            remote_id = atoi(str);
      }
   } else if (strstr(response, "Logbook Selection"))
      sprintf(error_str, "No logbook specified\n");
   else if (strstr(response, "enter password"))
      sprintf(error_str, "Missing or invalid password\n");
   else if (strstr(response, "form name=form1"))
      sprintf(error_str, "Missing or invalid user name/password\n");
   else if (strstr(response, "Error: Attribute")) {
      strncpy(str, strstr(response, "Error: Attribute") + 20, sizeof(str));
      if (strchr(str, '<'))
         *strchr(str, '<') = 0;
      sprintf(error_str, "Missing required attribute \"%s\"\n", str);
   } else
      sprintf(error_str, "Error transmitting message\n");

   free(text);

   if (error_str[0])
      return -1;

   return remote_id;
}

/*------------------------------------------------------------------*/

int receive_message(LOGBOOK * lbs, char *url, int message_id, char *error_str, BOOL bnew)
{
   int i, status, size, n_attr;
   char str[NAME_LENGTH], str2[NAME_LENGTH], *p, *p2, *message, date[80],
       attrib[MAX_N_ATTR][NAME_LENGTH], in_reply_to[80], reply_to[MAX_REPLY_TO * 10],
       encoding[80], locked_by[256], attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH],
       attachment_all[64 * MAX_ATTACHMENTS];

   error_str[0] = 0;

   combine_url(lbs, url, "", str, sizeof(str));
   sprintf(str + strlen(str), "%d?cmd=Download", message_id);

   retrieve_url(str, &message);
   p = strstr(message, "\r\n\r\n");
   if (p == NULL) {
      free(message);
      sprintf(error_str, loc("Cannot receive \"%s\""), str);
      return -1;
   }
   p += 4;

   /* check for correct ID */
   if (atoi(p + 8) != message_id) {
      free(message);
      sprintf(error_str, loc("Received wrong entry id \"%d\""), atoi(p + 8));
      return -1;
   }

   /* decode entry */
   el_decode(p, "Date: ", date);
   el_decode(p, "Reply to: ", reply_to);
   el_decode(p, "In reply to: ", in_reply_to);

   /* derive attribute names from message */
   for (i = 0;; i++) {
      el_enum_attr(p, i, attr_list[i], attrib[i]);
      if (!attr_list[i][0])
         break;
   }
   n_attr = i;

   el_decode(p, "Attachment: ", attachment_all);
   el_decode(p, "Encoding: ", encoding);

   /* break apart attachements */
   for (i = 0; i < MAX_ATTACHMENTS; i++)
      attachment[i][0] = 0;

   for (i = 0; i < MAX_ATTACHMENTS; i++) {
      if (i == 0)
         p2 = strtok(attachment_all, ",");
      else
         p2 = strtok(NULL, ",");

      if (p2 != NULL)
         strcpy(attachment[i], p2);
      else
         break;
   }

   el_decode(p, "Locked by: ", locked_by);
   if (locked_by[0]) {
      free(message);
      sprintf(error_str, loc("Entry #%d is locked on remote server"), message_id);
      return -1;
   }

   p = strstr(message, "========================================\n");

   /* check for \n -> \r conversion (e.g. zipping/unzipping) */
   if (p == NULL)
      p = strstr(message, "========================================\r");

   if (p != NULL) {
      p += 41;

      /* remove last CR */
      if (p[strlen(p) - 1] == '\n')
         p[strlen(p) - 1] = 0;

      status = el_submit(lbs, message_id, !bnew, date, attr_list,
                         attrib, n_attr, p, in_reply_to, reply_to,
                         encoding, attachment, FALSE, "");

      free(message);

      if (status != message_id) {
         sprintf(error_str, loc("Cannot save remote entry locally"));
         return -1;
      }

      for (i = 0; i < MAX_ATTACHMENTS; i++) {
         if (attachment[i][0]) {

            combine_url(lbs, url, "", str, sizeof(str));
            strlcpy(str2, attachment[i], sizeof(str2));
            str2[13] = '/';
            strlcat(str, str2, sizeof(str));

            size = retrieve_url(str, &message);
            p = strstr(message, "\r\n\r\n");
            if (p == NULL) {
               free(message);
               sprintf(error_str, loc("Cannot receive \"%s\""), str);
               return -1;
            }
            p += 4;

            el_submit_attachment(lbs, attachment[i], p, size, NULL);
            free(message);
         }
      }
   } else {
      free(message);
      return -1;
   }

   return 1;
}

/*------------------------------------------------------------------*/

void submit_config(LOGBOOK * lbs, char *server, char *buffer, char *error_str)
{
   int i, n, status, port, sock, content_length, header_length;
   char str[256];
   char host_name[256], subdir[256], param[256], local_host_name[256];
   char *content, *p, boundary[80], request[10000], response[10000];
   struct hostent *phe;
   struct sockaddr_in bind_addr;

   error_str[0] = 0;

   combine_url(lbs, server, "", str, sizeof(str));
   split_url(str, host_name, &port, subdir, param);

   /* create socket */
   if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
      strcpy(error_str, loc("Cannot create socket"));
      return;
   }

   /* get local host name */
   gethostname(local_host_name, sizeof(local_host_name));

   /* compose remote address */
   memset(&bind_addr, 0, sizeof(bind_addr));
   bind_addr.sin_family = AF_INET;
   bind_addr.sin_addr.s_addr = 0;
   bind_addr.sin_port = htons((unsigned short) port);

   phe = gethostbyname(host_name);
   if (phe == NULL) {
      closesocket(sock);
      sprintf(error_str, loc("Cannot resolve host name \"%s\""), host_name);
      return;
   }
   memcpy((char *) &(bind_addr.sin_addr), phe->h_addr, phe->h_length);

   /* connect to server */
   status = connect(sock, (void *) &bind_addr, sizeof(bind_addr));
   if (status != 0) {
      closesocket(sock);
      sprintf(error_str, loc("Cannot connect to host %s, port %d"), host_name, port);
      return;
   }

   content_length = 100000;
   content = malloc(content_length);
   if (content == NULL) {
      closesocket(sock);
      strcpy(error_str, loc("Not enough memory"));
      return;
   }

   /* compose content */
   srand((unsigned) time(NULL));
   sprintf(boundary, "---------------------------%04X%04X%04X", rand(), rand(), rand());
   strcpy(content, boundary);
   strcat(content, "\r\nContent-Disposition: form-data; name=\"cmd\"\r\n\r\nSave\r\n");

   if (isparam("unm"))
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"unm\"\r\n\r\n%s\r\n",
              boundary, getparam("unm"));

   if (isparam("upwd"))
      sprintf(content + strlen(content),
              "%s\r\nContent-Disposition: form-data; name=\"upwd\"\r\n\r\n%s\r\n",
              boundary, getparam("upwd"));

   sprintf(content + strlen(content),
           "%s\r\nContent-Disposition: form-data; name=\"Text\"\r\n\r\n%s\r\n%s\r\n",
           boundary, buffer, boundary);

   content_length = strlen(content);
   p = content + content_length;

   /* compose request */
   strcpy(request, "POST ");
   if (subdir[0]) {
      if (subdir[0] != '/')
         strcat(request, "/");
      strcat(request, subdir);
      if (request[strlen(request) - 1] != '/')
         strcat(request, "/");
   }
   strcat(request, " HTTP/1.0\r\n");

   sprintf(request + strlen(request),
           "Content-Type: multipart/form-data; boundary=%s\r\n", boundary);
   sprintf(request + strlen(request), "Host: %s\r\n", local_host_name);
   sprintf(request + strlen(request), "User-Agent: ELOGD\r\n");
   sprintf(request + strlen(request), "Content-Length: %d\r\n", content_length);

   if (isparam("wpwd"))
      sprintf(request + strlen(request), "Cookie: wpwd=%s\r\n", getparam("wpwd"));

   strcat(request, "\r\n");

   header_length = strlen(request);

   /* send request */
   send(sock, request, header_length, 0);

   /* send content */
   send(sock, content, content_length, 0);

   /* receive response */
   i = recv(sock, response, 10000, 0);
   if (i < 0) {
      closesocket(sock);
      strcpy(error_str, "Cannot receive response");
      return;
   }

   /* discard remainder of response */
   n = i;
   while (i > 0) {
      i = recv(sock, response + n, 10000, 0);
      if (i > 0)
         n += i;
   }
   response[n] = 0;

   closesocket(sock);

   /* check response status */
   if (strstr(response, "302 Found")) {
      if (strstr(response, "Location:")) {
         if (strstr(response, "wpwd"))
            sprintf(error_str, "Invalid password\n");
         else if (strstr(response, "wusr"))
            sprintf(error_str, "Invalid user name\n");
      }
   } else if (strstr(response, "Logbook Selection"))
      sprintf(error_str, "No logbook specified\n");
   else if (strstr(response, "enter password"))
      sprintf(error_str, "Missing or invalid password\n");
   else if (strstr(response, "form name=form1"))
      sprintf(error_str, "Missing or invalid user name/password\n");
   else if (strstr(response, "Error: Attribute")) {
      strncpy(str, strstr(response, "Error: Attribute") + 20, sizeof(str));
      if (strchr(str, '<'))
         *strchr(str, '<') = 0;
      sprintf(error_str, "Missing required attribute \"%s\"\n", str);
   } else
      sprintf(error_str, "Error transmitting message\n");
}

/*------------------------------------------------------------------*/

void receive_config(LOGBOOK * lbs, char *server, char *error_str)
{
   char str[256], *buffer, *p;

   error_str[0] = 0;

   combine_url(lbs, server, "", str, sizeof(str));
   sprintf(str + strlen(str), "?cmd=Download");
   retrieve_url(str, &buffer);
   p = strstr(buffer, "\r\n\r\n");
   if (p == NULL) {
      free(buffer);
      sprintf(error_str, loc("Cannot receive \"%s\""), str);
      return;
   }
   p += 4;

   if (!save_admin_config(lbs, lbs->name, p, str))
      rsprintf(str);

   free(buffer);
}

/*------------------------------------------------------------------*/

int save_md5(LOGBOOK * lbs, char *server, MD5_INDEX * md5_index, int n)
{
   char str[256], url[256], file_name[256];
   int i, j;
   FILE *f;

   combine_url(lbs, server, "", url, sizeof(url));
   url_decode(url);
   if (strstr(url, "http://"))
      strcpy(str, url + 7);
   else
      strcpy(str, url);

   for (i = 0; i < (int) strlen(str); i++)
      if (strchr(":/\\ ", str[i]))
         str[i] = '_';

   while (str[strlen(str) - 1] == '_')
      str[strlen(str) - 1] = 0;

   strlcpy(file_name, resource_dir, sizeof(file_name));
   strlcat(file_name, str, sizeof(file_name));
   strlcat(file_name, ".md5", sizeof(file_name));

   f = fopen(file_name, "wt");
   if (f == NULL)
      return -1;

   for (i = 0; i < n; i++) {
      fprintf(f, "ID%d: ", md5_index[i].message_id);
      for (j = 0; j < 16; j++)
         fprintf(f, "%02X", md5_index[i].md5_digest[j]);
      fprintf(f, "\n");
   }

   fclose(f);
   return 1;
}

/*------------------------------------------------------------------*/

int load_md5(LOGBOOK * lbs, char *server, MD5_INDEX ** md5_index)
{
   char str[256], url[256], file_name[256], *p;
   int i, j, x;
   FILE *f;

   *md5_index = NULL;

   combine_url(lbs, server, "", url, sizeof(url));
   url_decode(url);
   if (strstr(url, "http://"))
      strcpy(str, url + 7);
   else
      strcpy(str, url);

   for (i = 0; i < (int) strlen(str); i++)
      if (strchr(":/\\ ", str[i]))
         str[i] = '_';

   while (str[strlen(str) - 1] == '_')
      str[strlen(str) - 1] = 0;

   strlcpy(file_name, resource_dir, sizeof(file_name));
   strlcat(file_name, str, sizeof(file_name));
   strlcat(file_name, ".md5", sizeof(file_name));

   f = fopen(file_name, "rt");
   if (f == NULL)
      return 0;

   for (i = 0; !feof(f); i++) {
      str[0] = 0;
      fgets(str, sizeof(str), f);
      if (!str[0])
         break;

      if (i == 0)
         *md5_index = calloc(sizeof(MD5_INDEX), 1);
      else
         *md5_index = realloc(*md5_index, sizeof(MD5_INDEX) * (i + 1));

      p = str + 2;

      (*md5_index)[i].message_id = atoi(p);
      while (*p && *p != ' ')
         p++;
      while (*p && *p == ' ')
         p++;

      for (j = 0; j < 16; j++) {
         sscanf(p + j * 2, "%02X", &x);
         (*md5_index)[i].md5_digest[j] = (unsigned char) x;
      }
   }

   fclose(f);
   return i;
}

/*------------------------------------------------------------------*/

BOOL equal_md5(unsigned char m1[16], unsigned char m2[16])
{
   int i;
   for (i = 0; i < 16; i++)
      if (m1[i] != m2[i])
         break;

   return i == 16;
}

/*------------------------------------------------------------------*/

void synchronize_logbook(LOGBOOK * lbs, BOOL bcron)
{
   int index, i, j, i_msg, i_remote, i_cache, n_remote, n_cache, nserver,
       remote_id, exist_remote, exist_cache, message_id, max_id;
   int priority_remote = 0, all_identical;
   char str[2000], url[256], loc_ref[256], rem_ref[256];
   MD5_INDEX *md5_remote, *md5_cache;
   char list[MAX_N_LIST][NAME_LENGTH], error_str[256], *buffer;
   unsigned char digest[16];

   if (!getcfg(lbs->name, "Mirror server", str)) {
      show_error(loc("No mirror server defined in configuration file"));
      return;
   }

   nserver = strbreak(str, list, MAX_N_LIST);

   for (index = 0; index < nserver; index++) {

      if (!bcron) {
         rsprintf("<table width=\"100%%\" cellpadding=1 cellspacing=0");

         if (getcfg_topgroup())
            sprintf(loc_ref, "<a href=\"../%s/\">%s</a>", lbs->name_enc, lbs->name);
         else
            sprintf(loc_ref, "<a href=\"%s/\">%s</a>", lbs->name_enc, lbs->name);

         sprintf(str, loc("Synchronizing logbook %s with server \"%s\""), loc_ref,
                 list[index]);
         rsprintf("<tr><td class=\"title1\">%s</td></tr>\n", str);
         rsprintf("</table><p>\n");

         rsprintf("<pre>");
      }

      /* send partial return buffer */
      flush_return_buffer();

      n_remote = retrieve_remote_md5(lbs, list[index], &md5_remote, error_str);
      if (n_remote <= 0) {

         if (bcron)
            logf(lbs, error_str);
         else
            rsprintf("%s\n", error_str);

         if (md5_remote)
            free(md5_remote);

         if (!bcron)
            rsprintf("</pre>\n");
         continue;
      }

      /* load local copy of remote MD5s from file */
      n_cache = load_md5(lbs, list[index], &md5_cache);

      /*---- check for configuration file ----*/

      if (getcfg(lbs->name, "Mirror config", str) && atoi(str) == 1 && md5_cache) {

         load_config_section(lbs->name, &buffer, error_str);
         if (error_str[0]) {
            if (bcron)
               logf(lbs, "Error loading configuration file: %s", error_str);
            else
               rsprintf("Error loading configuration file: %s\n", error_str);
         } else
            MD5_checksum(buffer, strlen(buffer), digest);

         /* compare MD5s */
         /*
            printf("ID0:    ");
            for (j = 0; j < 16; j++)
            printf("%02X", digest[j]);
            printf("\nCache : ");
            for (j = 0; j < 16; j++)
            printf("%02X", md5_cache[0].md5_digest[j]);
            printf("\nRemote: ");
            for (j = 0; j < 16; j++)
            printf("%02X", md5_remote[0].md5_digest[j]);
            printf("\n\n");
          */

         if (n_remote > 0) {
            /* if config has been changed on this server, but not remotely, send it */
            if (!equal_md5(md5_cache[0].md5_digest, digest)
                && equal_md5(md5_cache[0].md5_digest, md5_remote[0].md5_digest)) {

               if (_logging_level > 1)
                  logf(lbs, "MIRROR send config");

               /* submit configuration section */
               if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
                  submit_config(lbs, list[index], buffer, error_str);

               if (error_str[0]) {
                  if (bcron)
                     logf(lbs, "Error sending config file: %s", error_str);
                  else
                     rsprintf("Error sending config file: %s\n", error_str);
               } else {
                  if (!bcron)
                     rsprintf("Local config submitted\n");
               }

               md5_cache[0].message_id = -1;

            } else
               /* if config has been changed remotely, but not on this server, receive it */
               if (!equal_md5(md5_cache[0].md5_digest, md5_remote[0].md5_digest)
                   && equal_md5(md5_cache[0].md5_digest, digest)) {

               if (_logging_level > 1)
                  logf(lbs, "MIRROR receive config");

               if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
                  receive_config(lbs, list[index], error_str);

               if (error_str[0]) {
                  if (bcron)
                     logf(lbs, "Error receiving config file: %s\n", error_str);
                  else
                     rsprintf("Error receiving config file: %s\n", error_str);
               } else {
                  if (!bcron)
                     rsprintf("Remote config received\n");
               }
               md5_cache[0].message_id = -1;

            } else
               /* if config has been changed remotely and on this server, show conflict */
               if (!equal_md5(md5_cache[0].md5_digest, md5_remote[0].md5_digest)
                   && !equal_md5(md5_cache[0].md5_digest, digest)
                   && !equal_md5(md5_remote[0].md5_digest, digest)) {

               if (_logging_level > 1)
                  logf(lbs, "MIRROR config conflict");

               if (!bcron) {
                  rsprintf("%s.\n",
                           loc("Configuration has been changed locally and remotely"));
                  rsprintf(loc("Please merge manually to resolve conflict"));
                  rsprintf(".\n");
               }

            } else {
               /* configs are identical */
               md5_cache[0].message_id = -1;
            }
         } else {               /* n_remote == 0 */

            sprintf(str, loc("Logbook \"%s\" does not exist on remote server"),
                    lbs->name);
            if (bcron)
               logf(lbs, str);
            rsprintf("%s\n", str);
            continue;

         }

         flush_return_buffer();

         if (buffer)
            free(buffer);
      }

      /*---- loop through logbook entries ----*/

      all_identical = TRUE;

      for (i_msg = 0; i_msg < *lbs->n_el_index; i_msg++) {

         message_id = lbs->el_index[i_msg].message_id;

         /* look for message id in MD5s */
         for (i_remote = 0; i_remote < n_remote; i_remote++)
            if (md5_remote[i_remote].message_id == message_id)
               break;
         exist_remote = i_remote < n_remote;

         for (i_cache = 0; i_cache < n_cache; i_cache++)
            if (md5_cache[i_cache].message_id == message_id)
               break;
         exist_cache = i_cache < n_cache;

         /* if message exists in both lists, compare MD5s */
         if (exist_remote && exist_cache) {

            /* if message has been changed on this server, but not remotely, send it */
            if (!equal_md5(md5_cache[i_cache].md5_digest, lbs->el_index[i_msg].md5_digest)
                && equal_md5(md5_cache[i_cache].md5_digest,
                             md5_remote[i_remote].md5_digest)) {

               if (_logging_level > 1)
                  logf(lbs, "MIRROR send entry #%d", message_id);

               /* submit local message */
               if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
                  submit_message(lbs, list[index], message_id, error_str);
               all_identical = FALSE;

               /* not that submit_message() may have changed attr_list !!! */

               if (error_str[0]) {
                  if (bcron)
                     logf(lbs, "Error sending local message: %s", error_str);
                  else
                     rsprintf("Error sending local message: %s\n", error_str);
               } else if (!bcron)
                  rsprintf("ID%d:\tLocal entry submitted\n", message_id);

               md5_cache[i_cache].message_id = -1;

            } else
               /* if message has been changed remotely, but not on this server, receive it */
               if (!equal_md5
                   (md5_cache[i_cache].md5_digest, md5_remote[i_remote].md5_digest)
                   && equal_md5(md5_cache[i_cache].md5_digest,
                                lbs->el_index[i_msg].md5_digest)) {

               if (_logging_level > 1)
                  logf(lbs, "MIRROR receive entry #%d", message_id);

               if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
                  receive_message(lbs, list[index], message_id, error_str, FALSE);
               all_identical = FALSE;

               if (error_str[0]) {
                  if (bcron)
                     logf(lbs, "Error receiving message: %s", error_str);
                  else
                     rsprintf("Error receiving message: %s\n", error_str);
               } else if (!bcron) {

                  if (getcfg_topgroup())
                     rsprintf("<a href=\"../%s/%d\">ID%d:</a>\t", lbs->name_enc,
                              message_id, message_id);
                  else
                     rsprintf("<a href=\"%s/%d\">ID%d:</a>\t", lbs->name_enc, message_id,
                              message_id);

                  rsprintf("%s\n", loc("Remote entry received"));
               }

               md5_cache[i_cache].message_id = -1;

            } else
               /* if message has been changed remotely and on this server, show conflict */
               if (!equal_md5
                   (md5_cache[i_cache].md5_digest, md5_remote[i_remote].md5_digest)
                   && !equal_md5(md5_cache[i_cache].md5_digest,
                                 lbs->el_index[i_msg].md5_digest)
                   && !equal_md5(md5_remote[i_remote].md5_digest,
                                 lbs->el_index[i_msg].md5_digest)) {

               if (_logging_level > 1)
                  logf(lbs, "MIRROR conflict entry #%d", message_id);

               combine_url(lbs, list[index], "", str, sizeof(str));
               sprintf(loc_ref, "<a href=\"%d\">%s</a>", message_id, loc("local"));
               sprintf(rem_ref, "<a href=\"http://%s%d\">%s</a>", str, message_id,
                       loc("remote"));

               all_identical = FALSE;

               if (!bcron) {
                  rsprintf("ID%d:\t%s.\n\t", message_id,
                           loc("Entry has been changed locally and remotely"));
                  rsprintf(loc("Please delete %s or %s entry to resolve conflict"),
                           loc_ref, rem_ref);
                  rsprintf(".\n");
               }

            } else {

               /* messages are identical */
               md5_cache[i_cache].message_id = -1;
            }
         }

         /* if message exists only in cache, but not remotely, 
            it must have been deleted remotely, so remove it locally */
         if (exist_cache && !exist_remote) {

            if (_logging_level > 1)
               logf(lbs, "MIRROR delete local entry #%d", message_id);

            if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
               el_delete_message(lbs, message_id, TRUE, NULL, TRUE, TRUE);
            all_identical = FALSE;

            if (!bcron)
               rsprintf("ID%d:\t%s\n", message_id, loc("Entry deleted locally"));

            /* message got deleted from local message list, so redo current index */
            i_msg--;

            /* mark message non-conflicting */
            md5_cache[i_cache].message_id = -1;
         }

         /* if message does not exist in cache and remotely, 
            it must be new, so send it  */
         if (!exist_cache && !exist_remote) {

            if (_logging_level > 1)
               logf(lbs, "MIRROR send entry #%d", message_id);

            if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
               remote_id = submit_message(lbs, list[index], message_id, error_str);
            all_identical = FALSE;

            if (remote_id != message_id) {
               if (bcron)
                  logf(lbs, "Error: Submitting entry #%d resulted in remote entry #%d\n",
                       message_id, remote_id);
               else
                  rsprintf("Error: Submitting entry #%d resulted in remote entry #%d\n",
                           message_id, remote_id);
            } else if (error_str[0]) {
               if (bcron)
                  logf(lbs, "%s: %s", loc("Error sending local entry"), error_str);
               else
                  rsprintf("%s: %s\n", loc("Error sending local entry"), error_str);
            } else if (!bcron)
               rsprintf("ID%d:\t%s\n", message_id, loc("Local entry submitted"));
         }

         /* if message does not exist in cache but remotely, 
            messages were added on both sides, so resubmit local one and retrieve remote one
            if messages are different */
         if (!exist_cache && exist_remote &&
             !equal_md5(md5_remote[i_remote].md5_digest,
                        lbs->el_index[i_msg].md5_digest)) {

            /* find max id both locally and remotely */
            max_id = 1;
            for (i = 0; i < *lbs->n_el_index; i++)
               if (lbs->el_index[i].message_id > max_id)
                  max_id = lbs->el_index[i].message_id;

            for (i = 0; i < n_remote; i++)
               if (md5_remote[i].message_id > max_id)
                  max_id = md5_remote[i].message_id;

            if (_logging_level > 1)
               logf(lbs, "MIRROR change entry #%d to #%d", message_id, max_id + 1);

            /* rearrange local message not to conflict with remote message */
            if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
               el_move_message(lbs, message_id, max_id + 1);
            all_identical = FALSE;

            if (!bcron) {
               sprintf(str, loc("Changed local entry ID to %d"), max_id + 1);
               rsprintf("ID%d:\t%s\n", message_id, str);
            }

            /* current message has been changed, so start over */
            i_msg--;
         }

         flush_return_buffer();
      }

      /* go through remote message which do not exist locally */
      for (i_remote = 0; i_remote < n_remote; i_remote++)
         if (md5_remote[i_remote].message_id) {

            message_id = md5_remote[i_remote].message_id;

            for (i_msg = 0; i_msg < *lbs->n_el_index; i_msg++)
               if (message_id == lbs->el_index[i_msg].message_id)
                  break;

            if (i_msg == *lbs->n_el_index) {

               for (i_cache = 0; i_cache < n_cache; i_cache++)
                  if (md5_cache[i_cache].message_id == message_id)
                     break;
               exist_cache = i_cache < n_cache;

               if (!exist_cache) {

                  if (_logging_level > 1)
                     logf(lbs, "MIRROR receive entry #%d", message_id);

                  /* if message does not exist locally and in cache, it is new, so retrieve it */
                  if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
                     receive_message(lbs, list[index], message_id, error_str, TRUE);
                  all_identical = FALSE;

                  if (error_str[0]) {
                     if (bcron)
                        logf(lbs, "Error receiving message: %s", error_str);
                     else
                        rsprintf("Error receiving message: %s\n", error_str);
                  } else if (!bcron) {

                     if (getcfg_topgroup())
                        rsprintf("<a href=\"../%s/%d\">ID%d:</a>\t", lbs->name_enc,
                                 message_id, message_id);
                     else
                        rsprintf("<a href=\"%s/%d\">ID%d:</a>\t", lbs->name_enc,
                                 message_id, message_id);

                     rsprintf("%s\n", loc("Remote entry received"));
                  }

               } else {

                  /* if message does not exist locally but in cache, delete remote message */
                  if (_logging_level > 1)
                     logf(lbs, "MIRROR delete remote entry #%d", message_id);

                  sprintf(str, "%d?cmd=Delete&confirm=Yes", message_id);
                  combine_url(lbs, list[index], str, url, sizeof(url));

                  all_identical = FALSE;
                  if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0) {
                     retrieve_url(url, &buffer);

                     if (strstr(buffer, "Location: ")) {
                        if (!bcron)
                           rsprintf("ID%d:\t%s\n", message_id,
                                    loc("Entry deleted remotely"));
                     } else {
                        if (bcron)
                           logf(lbs, "%s", loc("Error deleting remote entry"));
                        else
                           rsprintf("%s\n", loc("Error deleting remote entry"));
                     }

                     free(buffer);
                  } else
                     rsprintf("ID%d:\t%s\n", message_id, loc("Entry deleted remotely"));

                  md5_cache[i_cache].message_id = -1;
               }
            }

            flush_return_buffer();
         }

      free(md5_remote);

      /* save remote MD5s in file */
      n_remote = retrieve_remote_md5(lbs, list[index], &md5_remote, error_str);
      if (n_remote < 0)
         rsprintf("%s\n", error_str);

      /* keep conflicting messages in cache */
      for (i = 0; i < n_cache; i++)
         if (md5_cache[i].message_id != -1) {

            if (i == 0)
               memcpy(md5_remote[0].md5_digest, md5_cache[0].md5_digest, 16);
            else
               for (j = 0; j < n_remote; j++)
                  if (md5_remote[j].message_id == md5_cache[i].message_id) {
                     memcpy(md5_remote[j].md5_digest, md5_cache[i].md5_digest, 16);
                     break;
                  }
         }

      if (!getcfg(lbs->name, "Mirror simulate", str) || atoi(str) == 0)
         save_md5(lbs, list[index], md5_remote, n_remote);

      if (md5_remote)
         free(md5_remote);
      if (md5_cache)
         free(md5_cache);

      if (!bcron && all_identical)
         rsprintf(loc("All entries identical"));

      if (!bcron)
         rsprintf("</pre>\n");
   }


   flush_return_buffer();
   keep_alive = 0;
}

/*------------------------------------------------------------------*/

void synchronize(LOGBOOK * lbs, BOOL bcron)
{
   int i;
   char str[256], pwd[256];

   if (!bcron) {
      show_html_header(NULL, FALSE, loc("Synchronization"), TRUE);
      rsprintf("<body>\n");
   }

   if (lbs == NULL) {
      for (i = 0; lb_list[i].name[0]; i++)
         if (getcfg(lb_list[i].name, "mirror server", str)) {

            if (exist_top_group() && getcfg_topgroup())
               if (lb_list[i].top_group[0]
                   && !equal_ustring(lb_list[i].top_group, getcfg_topgroup()))
                  continue;

            /* if called by cron, set user name and password */
            if (bcron && getcfg(lb_list[i].name, "mirror user", str)) {
               if (get_user_line(lb_list[i].name, str, pwd, NULL, NULL, NULL) ==
                   EL_SUCCESS) {
                  setparam("unm", str);
                  setparam("upwd", pwd);
               }
            }

            synchronize_logbook(&lb_list[i], bcron);
         }
   } else
      synchronize_logbook(lbs, bcron);

   if (!bcron) {
      rsprintf("<table width=\"100%%\" cellpadding=1 cellspacing=0");
      rsprintf("<tr><td class=\"seltitle\"><a href=\".\">%s</a></td></tr>\n",
               loc("Back"));
      rsprintf("</table><p>\n");

      rsprintf("</body></html>\n");
      flush_return_buffer();
      keep_alive = 0;
   }
}

/*------------------------------------------------------------------*/

void display_line(LOGBOOK * lbs, int message_id, int number, char *mode,
                  int expand, int level, BOOL printable, int n_line,
                  int show_attachments, char *date, char *in_reply_to,
                  char *reply_to, int n_attr_disp,
                  char disp_attr[MAX_N_ATTR + 4][NAME_LENGTH],
                  char attrib[MAX_N_ATTR][NAME_LENGTH], int n_attr,
                  char *text,
                  char attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH], char *encoding,
                  BOOL select, int *n_display, char *locked_by)
{
   char str[NAME_LENGTH], ref[256], *nowrap, sclass[80], format[256],
       file_name[MAX_PATH_LENGTH];
   char slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH];
   char display[NAME_LENGTH], attr_icon[80];
   int i, j, i_line, index, colspan;
   BOOL skip_comma;
   FILE *f;
   struct tm ts;

   sprintf(ref, "../%s/%d", lbs->name_enc, message_id);

   if (equal_ustring(mode, "Summary")) {
      if (number % 2 == 1)
         strcpy(sclass, "list1");
      else
         strcpy(sclass, "list2");
   } else if (equal_ustring(mode, "Full"))
      strcpy(sclass, "list1");
   else if (equal_ustring(mode, "Threaded")) {
      if (level == 0)
         strcpy(sclass, "thread");
      else
         strcpy(sclass, "threadreply");
   }

   rsprintf("<tr>");

   /* only single cell for threaded display */
   if (equal_ustring(mode, "Threaded")) {
      rsprintf("<td align=left class=\"%s\">", sclass);

      if (locked_by && locked_by[0]) {
         sprintf(str, "%s %s", loc("Entry is currently edited by"), locked_by);
         rsprintf("<img src=\"stop.gif\" alt=\"%s\">&nbsp;", str);
      }

      /* show select box */
      if (select && level == 0)
         rsprintf("<input type=checkbox name=\"s%d\" value=%d>\n", (*n_display)++,
                  message_id);

      for (i = 0; i < level; i++)
         rsprintf("&nbsp;&nbsp;&nbsp;");

      /* display "+" if expandable */
      if (expand == 0 && reply_to[0])
         rsprintf("+&nbsp;");
   }

   nowrap = printable ? "" : "nowrap";
   skip_comma = FALSE;

   if (equal_ustring(mode, "Threaded")
       && getcfg(lbs->name, "Thread display", display)) {
      /* check if to use icon from attributes */
      attr_icon[0] = 0;
      if (getcfg(lbs->name, "Thread icon", attr_icon)) {
         for (i = 0; i < n_attr; i++)
            if (equal_ustring(attr_list[i], attr_icon))
               break;
         if (i < n_attr && attrib[i][0])
            strcpy(attr_icon, attrib[i]);
         else
            attr_icon[0] = 0;
      }

      if (attr_icon[0])
         rsprintf("<a href=\"%s\"><img border=0 src=\"icons/%s\"></a>&nbsp;", ref,
                  attr_icon);
      else {
         /* if top level only, display reply icon if message has a reply */
         if (getcfg(lbs->name, "Top level only", str) && atoi(str) == 1 && reply_to[0])
            rsprintf("<a href=\"%s\"><img border=0 src=\"reply.gif\"></a>&nbsp;", ref);
         else {
            /* display standard icons */
            if (level == 0)
               rsprintf("<a href=\"%s\"><img border=0 src=\"entry.gif\"></a>&nbsp;");
            else
               rsprintf("<a href=\"%s\"><img border=0 src=\"reply.gif\"></a>&nbsp;", ref);
         }
      }

      j = build_subst_list(lbs, slist, svalue, attrib);

      /* add message id and entry date */
      strcpy(slist[j], "Message ID");
      sprintf(svalue[j++], "%d", message_id);

      strcpy(slist[j], "entry date");

      if (!getcfg(lbs->name, "Date format", format))
         strcpy(format, DEFAULT_DATE_FORMAT);

      memset(&ts, 0, sizeof(ts));

      for (i = 0; i < 12; i++)
         if (strncmp(date + 4, mname[i], 3) == 0)
            break;
      ts.tm_mon = i;

      ts.tm_mday = atoi(date + 8);
      ts.tm_hour = atoi(date + 11);
      ts.tm_min = atoi(date + 14);
      ts.tm_sec = atoi(date + 17);
      ts.tm_year = atoi(date + 20) - 1900;
      ts.tm_isdst = -1;         /* let mktime compute DST */

      mktime(&ts);
      strftime(svalue[j++], sizeof(str), format, &ts);

      strsubst(display, slist, svalue, j);

      rsprintf("<a href=\"%s\">", ref);
      rsputs2(display);
      rsprintf("</a>\n");
   } else {
      /* show select box */
      if (select && !equal_ustring(mode, "Threaded")) {
         rsprintf("<td class=\"%s\">", sclass);

         if (in_reply_to[0] == 0)
            rsprintf("<input type=checkbox name=\"s%d\" value=%d>\n", (*n_display)++,
                     message_id);
         else
            rsprintf("&nbsp;\n");

         rsprintf("</td>\n");
      }

      if (equal_ustring(mode, "Threaded"))
         rsprintf("<a href=\"%s\">", ref);

      for (index = 0; index < n_attr_disp; index++) {
         if (equal_ustring(disp_attr[index], loc("ID"))) {
            if (equal_ustring(mode, "Threaded")) {
               if (level == 0)
                  rsprintf("<img border=0 src=\"entry.gif\">&nbsp;");
               else
                  rsprintf("<img border=0 src=\"reply.gif\">&nbsp;");

               skip_comma = TRUE;
            } else {
               rsprintf("<td class=\"%s\">", sclass);

               if (locked_by && locked_by[0]) {
                  sprintf(str, "%s %s", loc("Entry is currently edited by"), locked_by);
                  rsprintf("<img src=\"stop.gif\" alt=\"%s\">&nbsp;", str);
               }

               rsprintf("<a href=\"%s\">&nbsp;&nbsp;%d&nbsp;&nbsp;</a></td>\n", ref,
                        message_id);
            }
         }

         if (equal_ustring(disp_attr[index], loc("Logbook"))) {
            if (equal_ustring(mode, "Threaded")) {
               if (skip_comma) {
                  rsprintf(" %s", lbs->name);
                  skip_comma = FALSE;
               } else
                  rsprintf(", %s", lbs->name);
            } else
               rsprintf("<td class=\"%s\" %s><a href=\"%s\">%s</a></td>\n", sclass,
                        nowrap, ref, lbs->name);
         }

         if (equal_ustring(disp_attr[index], loc("Date"))) {
            if (!getcfg(lbs->name, "Date format", format))
               strcpy(format, DEFAULT_DATE_FORMAT);

            memset(&ts, 0, sizeof(ts));

            for (i = 0; i < 12; i++)
               if (strncmp(date + 4, mname[i], 3) == 0)
                  break;
            ts.tm_mon = i;

            ts.tm_mday = atoi(date + 8);
            ts.tm_hour = atoi(date + 11);
            ts.tm_min = atoi(date + 14);
            ts.tm_sec = atoi(date + 17);
            ts.tm_year = atoi(date + 20) - 1900;
            ts.tm_isdst = -1;   /* let mktime compute DST */

            mktime(&ts);
            strftime(str, sizeof(str), format, &ts);

            if (equal_ustring(mode, "Threaded")) {
               if (skip_comma) {
                  rsprintf(" %s", str);
                  skip_comma = FALSE;
               } else
                  rsprintf(", %s", str);
            } else
               rsprintf("<td class=\"%s\" %s><a href=\"%s\">%s</a></td>\n", sclass,
                        nowrap, ref, str);
         }

         for (i = 0; i < n_attr; i++)
            if (equal_ustring(disp_attr[index], attr_list[i])) {
               if (equal_ustring(mode, "Threaded")) {
                  if (equal_ustring(attr_options[i][0], "boolean")) {
                     if (atoi(attrib[i]) == 1) {
                        if (skip_comma) {
                           rsprintf(" ");
                           skip_comma = FALSE;
                        } else
                           rsprintf(", ");

                        rsputs2(attrib[i]);

                        rsprintf("&nbsp");
                     }
                  }

                  else if (attr_flags[i] & AF_ICON) {
                     if (attrib[i][0])
                        rsprintf("&nbsp;<img border=0 src=\"icons/%s\">&nbsp;",
                                 attrib[i]);
                  }

                  else {
                     if (skip_comma) {
                        rsprintf(" ");
                        skip_comma = FALSE;
                     } else
                        rsprintf(", ");

                     rsputs2(attrib[i]);
                  }
               } else {
                  if (equal_ustring(attr_options[i][0], "boolean")) {
                     if (atoi(attrib[i]) == 1)
                        rsprintf
                            ("<td class=\"%s\"><input type=checkbox checked disabled></td>\n",
                             sclass);
                     else
                        rsprintf("<td class=\"%s\"><input type=checkbox disabled></td>\n",
                                 sclass);
                  }

                  else if (attr_flags[i] & AF_ICON) {
                     rsprintf("<td class=\"%s\">", sclass);
                     if (attrib[i][0])
                        rsprintf("<img border=0 src=\"icons/%s\">", attrib[i]);
                     rsprintf("&nbsp</td>");
                  }

                  else {
                     rsprintf("<td class=\"%s\"><a href=\"%s\">", sclass, ref);
                     rsputs2(attrib[i]);
                     rsprintf("&nbsp</a></td>");
                  }
               }
            }
      }

      if (equal_ustring(mode, "Threaded"))
         rsprintf("</a>\n");
   }

   if (equal_ustring(mode, "Threaded") && expand > 1) {
      rsprintf("</td></tr>\n");

      rsprintf("<tr><td class=\"summary\">");

      if (expand == 2) {
         for (i = i_line = 0; i < sizeof(str) - 1; i++) {
            str[i] = text[i];
            if (str[i] == '\n')
               i_line++;

            if (i_line == n_line)
               break;
         }
         str[i] = 0;

         /* always encode, not to rip apart HTML documents,
            e.g. only the start of a table */
         strencode(str);
      } else {
         if (equal_ustring(encoding, "plain")) {
            rsputs("<pre>");
            rsputs2(text);
            rsputs("</pre>");
         } else
            rsputs(text);

      }

      rsprintf("</td></tr>\n");
   }


   if ((equal_ustring(mode, "Summary") && n_line > 0)) {
      rsprintf("<td class=\"summary\">");
      for (i = i_line = 0; i < sizeof(str) - 1; i++) {
         str[i] = text[i];
         if (str[i] == '\n')
            i_line++;

         if (i_line == n_line)
            break;
      }
      str[i] = 0;

      /* always encode, not to rip apart HTML documents,
         e.g. only the start of a table */
      strencode(str);

      rsprintf("&nbsp;</td>\n");

      if (equal_ustring(mode, "Threaded"))
         rsprintf("</tr>\n");
   }

   colspan = n_attr_disp;

   if (select)
      colspan++;

   if (equal_ustring(mode, "Full")) {
      if (!getcfg(lbs->name, "Show text", str) || atoi(str) == 1) {
         rsprintf("<tr><td class=\"messagelist\" colspan=%d>", colspan);

         if (equal_ustring(encoding, "plain")) {
            rsputs("<pre>");
            rsputs2(text);
            rsputs("</pre>");
         } else
            rsputs(text);

         rsprintf("</td></tr>\n");
      }

      if (!show_attachments && attachment[0][0]) {
         rsprintf("<tr><td class=\"messagelist\" colspan=%d>", colspan);

         if (attachment[1][0])
            rsprintf("%s: ", loc("Attachments"));
         else
            rsprintf("%s: ", loc("Attachment"));
      }

      for (index = 0; index < MAX_ATTACHMENTS; index++) {
         if (attachment[index][0]) {
            strcpy(str, attachment[index]);
            str[13] = 0;
            sprintf(ref, "../%s/%s/%s", lbs->name, str, attachment[index] + 14);
            url_encode(ref, sizeof(ref));       /* for file names with special characters like "+" */

            for (i = 0; i < (int) strlen(attachment[index]); i++)
               str[i] = toupper(attachment[index][i]);
            str[i] = 0;

            if (!show_attachments) {
               rsprintf("<a href=\"%s\">%s</a>&nbsp;&nbsp;&nbsp;&nbsp; ", ref,
                        attachment[index] + 14);
            } else {
               if (strstr(str, ".GIF") || strstr(str, ".JPG") || strstr(str, ".JPEG")
                   || strstr(str, ".PNG")) {
                  rsprintf
                      ("<tr><td colspan=%d class=\"attachment\">%s %d: <a href=\"%s\">%s</a>\n",
                       colspan, loc("Attachment"), index + 1, ref,
                       attachment[index] + 14);
                  if (show_attachments)
                     rsprintf
                         ("</td></tr><tr><td colspan=%d class=\"messagelist\"><img src=\"%s\"></td></tr>",
                          colspan, ref);
               } else {
                  rsprintf
                      ("<tr><td colspan=%d class=\"attachment\">%s %d: <a href=\"%s\">%s</a>\n",
                       colspan, loc("Attachment"), index + 1, ref,
                       attachment[index] + 14);

                  if ((strstr(str, ".TXT") || strstr(str, ".ASC")
                       || strchr(str, '.') == NULL) && show_attachments) {
                     /* display attachment */
                     rsprintf("</td></tr><tr><td colspan=%d class=\"messagelist\"><pre>",
                              colspan);

                     strlcpy(file_name, lbs->data_dir, sizeof(file_name));

                     strlcat(file_name, attachment[index], sizeof(file_name));

                     f = fopen(file_name, "rt");
                     if (f != NULL) {
                        while (!feof(f)) {
                           str[0] = 0;
                           fgets(str, sizeof(str), f);
                           rsputs2(str);
                        }
                        fclose(f);
                     }

                     rsprintf("</pre>\n");
                  }
                  rsprintf("</td></tr>\n");
               }
            }
         }
      }

      if (!show_attachments && attachment[0][0])
         rsprintf("</td></tr>\n");
   }
}

/*------------------------------------------------------------------*/

void display_reply(LOGBOOK * lbs, int message_id, int printable,
                   int expand, int n_line, int n_attr_disp,
                   char disp_attr[MAX_N_ATTR + 4][NAME_LENGTH], int level)
{
   char *date, *text, *in_reply_to, *reply_to, *encoding, *locked_by, *attachment,
       *attrib, *p;
   int status, size;

   text = malloc(TEXT_SIZE);
   attachment = malloc(MAX_ATTACHMENTS * MAX_PATH_LENGTH);
   attrib = malloc(MAX_N_ATTR * NAME_LENGTH);
   date = malloc(80);
   in_reply_to = malloc(80);
   reply_to = malloc(256);
   encoding = malloc(80);
   locked_by = malloc(256);

   if (locked_by == NULL)
      return;

   reply_to[0] = 0;
   size = TEXT_SIZE;
   status =
       el_retrieve(lbs, message_id, date, attr_list, (void *) attrib,
                   lbs->n_attr, text, &size, in_reply_to, reply_to, (void *) attachment,
                   encoding, locked_by);

   if (status != EL_SUCCESS) {
      free(text);
      free(attachment);
      free(attrib);
      free(date);
      free(in_reply_to);
      free(reply_to);
      free(encoding);
      free(locked_by);
      return;
   }

   display_line(lbs, message_id, 0, "threaded", expand, level, printable,
                n_line, FALSE, date, in_reply_to, reply_to, n_attr_disp,
                disp_attr, (void *) attrib, lbs->n_attr, text, NULL, encoding, 0, NULL,
                locked_by);

   if (reply_to[0]) {
      p = reply_to;
      do {
         display_reply(lbs, atoi(p), printable, expand, n_line, n_attr_disp, disp_attr,
                       level + 1);

         while (*p && isdigit(*p))
            p++;
         while (*p && (*p == ',' || *p == ' '))
            p++;
      } while (*p);
   }

   free(text);
   free(attachment);
   free(attrib);
   free(date);
   free(in_reply_to);
   free(reply_to);
   free(encoding);
   free(locked_by);
}

/*------------------------------------------------------------------*/

int msg_compare(const void *m1, const void *m2)
{
   return strcoll(((MSG_LIST *) m1)->string, ((MSG_LIST *) m2)->string);
}

int msg_compare_reverse(const void *m1, const void *m2)
{
   return strcoll(((MSG_LIST *) m2)->string, ((MSG_LIST *) m1)->string);
}

/*------------------------------------------------------------------*/

char *param_in_str(char *str, char *param)
{
   char *p;

   p = str;
   do {
      if (strstr(p, param) == NULL)
         return NULL;

      p = strstr(p, param);

      /* if parameter is value of another parameter, skip it */
      if (p > str + 1 && *(p - 1) == '=')
         p += strlen(param);
      else
         return p;

      if (*p == 0)
         return NULL;

   } while (1);
}

/*------------------------------------------------------------------*/

void subst_param(char *str, int size, char *param, char *value)
{
   int len;
   char *p1, *p2, *s;

   if (!value[0]) {
      /* remove parameter */
      s = param_in_str(str, param);

      if (s == NULL)
         return;

      /* remove parameter */
      p1 = s - 1;

      for (p2 = p1 + strlen(param) + 1; *p2 && *p2 != '&'; p2++);
      strlcpy(p1, p2, size - ((int) p1 - (int) str));

      if (!strchr(str, '?') && strchr(str, '&'))
         *strchr(str, '&') = '?';

      return;
   }

   if ((p1 = param_in_str(str, param)) == NULL) {
      if (strchr(str, '?'))
         strlcat(str, "&", size);
      else
         strlcat(str, "?", size);

      strlcat(str, param, size);
      strlcat(str, "=", size);
      strlcat(str, value, size);
      return;
   }

   p1 += strlen(param) + 1;
   for (p2 = p1; *p2 && *p2 != '&'; p2++);
   len = (int) p2 - (int) p1;
   if (len > (int) strlen(value)) {
      /* new value is shorter than old one */
      strlcpy(p1, value, size - ((int) p1 - (int) str));
      strlcpy(p1 + strlen(value), p2, size - ((int) p1 + strlen(value) - (int) str));
   } else {
      /* new value is longer than old one */
      s = malloc(size);
      strlcpy(s, p2, size);
      strlcpy(p1, value, size - ((int) p1 - (int) str));
      strlcat(p1, s, size - ((int) p1 + strlen(value) - (int) str));
      free(s);
   }

}

/*------------------------------------------------------------------*/

BOOL is_user_allowed(LOGBOOK * lbs, char *command)
{
   char str[1000], users[2000];
   char list[MAX_N_LIST][NAME_LENGTH];
   int i, n;

   /* check for user level access */
   if (!getcfg(lbs->name, "Password file", str))
      return TRUE;

   /* check for deny */
   sprintf(str, "Deny %s", command);
   if (getcfg(lbs->name, str, users)) {
      /* check if current user in list */
      n = strbreak(users, list, MAX_N_LIST);
      for (i = 0; i < n; i++)
         if (equal_ustring(list[i], getparam("unm")))
            break;

      if (i < n)
         return FALSE;
   }

   /* check admin command */
   if (equal_ustring(command, loc("Admin"))) {
      if (getcfg(lbs->name, "Admin user", str)) {
         if (strstr(str, getparam("unm")) != 0)
            return TRUE;
         else
            return FALSE;
      }
   }

   /* check for allow */
   sprintf(str, "Allow %s", command);
   if (!getcfg(lbs->name, str, users))
      return TRUE;

   /* check if current user in list */
   n = strbreak(users, list, MAX_N_LIST);
   for (i = 0; i < n; i++)
      if (equal_ustring(list[i], getparam("unm")))
         return TRUE;

   return FALSE;
}

/*------------------------------------------------------------------*/

BOOL is_command_allowed(LOGBOOK * lbs, char *command)
{
   char str[1000], menu_str[1000], other_str[1000];
   char menu_item[MAX_N_LIST][NAME_LENGTH], admin_user[80];
   int i, n;

   if (command[0] == 0)
      return TRUE;

   /* check for guest access */
   if (!getcfg(lbs->name, "Guest Menu commands", menu_str) || *getparam("unm") != 0)
      getcfg(lbs->name, "Menu commands", menu_str);

   /* default menu commands */
   if (menu_str[0] == 0) {
      strcpy(menu_str, "Back, New, Edit, Delete, Reply, Find, ");

      if (getcfg(lbs->name, "Password file", str)) {

         if (!getcfg(lbs->name, "Admin user", str)
             || strstr(str, getparam("unm")) != 0) {

            strcat(menu_str, "Admin, ");
            strcat(menu_str, "Change elogd.cfg, ");

            if (getcfg(lbs->name, "Mirror server", str))
               strcat(menu_str, "Synchronize, ");

            if (!getcfg("global", "Admin user", str)
                || strstr(str, getparam("unm")) != 0) {

               if (lbs->top_group[0]) {
                  sprintf(str, "Change [global %s]", lbs->top_group);
                  strcat(menu_str, str);
                  strcat(menu_str, ", ");
               }

               if (!lbs->top_group[0] || (!getcfg_simple("global", "Admin user", str)
                                          || strstr(str, getparam("unm")) != 0)) {

                  strcat(menu_str, "Change [global]");
                  strcat(menu_str, ", ");
               }
            }
         }
         strcat(menu_str, "Config, Logout, ");
      } else {
         if (getcfg(lbs->name, "Mirror server", str))
            strcat(menu_str, "Synchronize, ");
         strcat(menu_str, "Config, ");
         strcat(menu_str, "Change [global]");
         strcat(menu_str, ", ");
      }

      strcat(menu_str, "Help, ");
   } else {
      /* check for admin command */
      n = strbreak(menu_str, menu_item, MAX_N_LIST);
      menu_str[0] = 0;
      admin_user[0] = 0;
      getcfg(lbs->name, "Admin user", admin_user);
      for (i = 0; i < n; i++) {
         if (strcmp(menu_item[i], "Admin") == 0) {
            if (strstr(admin_user, getparam("unm")) == NULL)
               continue;
         }
         strcat(menu_str, menu_item[i]);
         strcat(menu_str, ", ");
      }

      if (strstr(admin_user, getparam("unm")) != NULL) {

         strcat(menu_str, "Change elogd.cfg, ");

         if (!getcfg("global", "Admin user", str)
             || strstr(str, getparam("unm")) != 0) {

            if (lbs->top_group[0]) {
               sprintf(str, "Change [global %s]", lbs->top_group);
               strcat(menu_str, str);
               strcat(menu_str, ", ");
            }

            if (!lbs->top_group[0] || (!getcfg_simple("global", "Admin user", str)
                                       || strstr(str, getparam("unm")) != 0)) {

               strcat(menu_str, "Change [global]");
               strcat(menu_str, ", ");
            }
         }
      }
   }

   /* check find menu commands */
   str[0] = 0;
   if (!getcfg(lbs->name, "Guest Find Menu commands", str) || *getparam("unm") != 0)
      getcfg(lbs->name, "Find Menu commands", str);

   if (str[0])
      strlcat(menu_str, str, sizeof(menu_str));
   else {
      strlcat(menu_str, "New, Find, Select, Last x, Help, ", sizeof(menu_str));

      if (getcfg(lbs->name, "Password file", str))
         strlcat(menu_str, "Admin, Config, Logout, ", sizeof(menu_str));
      else
         strlcat(menu_str, "Config, ", sizeof(menu_str));
   }

   strcpy(other_str,
          "Update, Upload, Submit, Back, Search, Save, Download, Cancel, First, Last, Previous, Next, Requested, Forgot, ");

   /* admin commands */
   if (getcfg(lbs->name, "Admin user", str) && *getparam("unm")
       && strstr(str, getparam("unm")) != 0) {
      strcat(other_str, "Remove user, New user, Activate, ");
   } else if (getcfg(lbs->name, "Self register", str) && atoi(str) > 0) {
      strcat(other_str, "Remove user, New user, ");
   }

   /* allow change password if "config" possible */
   if (equal_ustring(command, loc("Change password")) && strstr(menu_str, "Config")) {
      return TRUE;
   }
   /* exclude non-localized submit for elog */
   else if (command[0] && equal_ustring(command, "Submit")) {
      return TRUE;
   }
   /* exclude other non-localized commands */
   else if (command[0] && equal_ustring(command, "GetMD5")) {
      return TRUE;
   }
   /* check if command is present in the menu list */
   else if (command[0]) {
      n = strbreak(menu_str, menu_item, MAX_N_LIST);
      for (i = 0; i < n; i++)
         if (equal_ustring(command, menu_item[i]) ||
             equal_ustring(command, loc(menu_item[i])))
            break;

      if (i == n) {
         n = strbreak(other_str, menu_item, MAX_N_LIST);
         for (i = 0; i < n; i++)
            if (equal_ustring(command, loc(menu_item[i])))
               break;

         if (i == n)
            return FALSE;
      }
   }

   return TRUE;
}

/*------------------------------------------------------------------*/

void build_ref(char *ref, int size, char *mode, char *expand)
{
   if (strchr(getparam("cmdline"), '?'))
      strlcat(ref, strchr(getparam("cmdline"), '?'), size);

   /* eliminate old search */
   if (strstr(ref, "cmd=Search&"))
      strcpy(strstr(ref, "cmd=Search&"), strstr(ref, "cmd=Search&") + 11);

   /* eliminate old mode if new one is present */
   if (mode[0])
      subst_param(ref, size, "mode", mode);

   /* eliminate old expand if new one is present */
   if (expand[0])
      subst_param(ref, size, "expand", expand);

   /* eliminate old last= */
   subst_param(ref, size, "last", getparam("last"));
}

/*------------------------------------------------------------------*/

void show_page_filters(LOGBOOK * lbs, int n_msg, int page_n, int n_page, BOOL top,
                       BOOL mode_commands, BOOL threaded)
{
   int cur_exp, n, i, j, index;
   char ref[256], str[NAME_LENGTH], comment[NAME_LENGTH];
   char list[MAX_N_LIST][NAME_LENGTH], option[NAME_LENGTH];

   rsprintf("<tr><td class=\"menuframe\">\n");
   rsprintf("<table width=\"100%%\" border=0 cellpadding=0 cellspacing=0>\n");

   rsprintf("<tr>\n");

   if (mode_commands) {
      rsprintf("<td class=\"menu2a\">\n");

      if (!getcfg(lbs->name, "Show text", str) || atoi(str) == 1) {
         if (page_n != 1)
            sprintf(ref, "page%d", page_n);
         else
            ref[0] = 0;
         build_ref(ref, sizeof(ref), "full", "");
         rsprintf("&nbsp;<a href=\"%s\">%s</a>&nbsp;|", ref, loc("Full"));
      }

      if (page_n != 1)
         sprintf(ref, "page%d", page_n);
      else
         ref[0] = 0;
      build_ref(ref, sizeof(ref), "summary", "");
      rsprintf("&nbsp;<a href=\"%s\">%s</a>&nbsp;|", ref, loc("Summary"));

      if (page_n != 1)
         sprintf(ref, "page%d", page_n);
      else
         ref[0] = 0;
      build_ref(ref, sizeof(ref), "threaded", "");
      rsprintf("&nbsp;<a href=\"%s\">%s</a>&nbsp;", ref, loc("Threaded"));

      if (threaded) {
         if (page_n != 1)
            sprintf(ref, "page%d", page_n);
         else
            ref[0] = 0;

         cur_exp = 1;
         if (getcfg(lbs->name, "Expand default", str))
            cur_exp = atoi(str);
         if (isparam("expand"))
            cur_exp = atoi(getparam("expand"));

         if (cur_exp > 0) {
            sprintf(str, "%d", cur_exp > 0 ? cur_exp - 1 : 0);
            build_ref(ref, sizeof(ref), "", str);
            rsprintf("|&nbsp;<a href=\"%s\">%s</a>&nbsp;", ref, loc("Collapse"));
         } else
            rsprintf("|&nbsp;%s&nbsp;", loc("Collapse"));

         if (cur_exp < 3) {
            if (page_n != 1)
               sprintf(ref, "page%d", page_n);
            else
               ref[0] = 0;
            sprintf(str, "%d", cur_exp < 3 ? cur_exp + 1 : 3);
            build_ref(ref, sizeof(ref), "", str);
            rsprintf("|&nbsp;<a href=\"%s\">%s</a>&nbsp;", ref, loc("Expand"));
         } else
            rsprintf("|&nbsp;%s&nbsp;", loc("Expand"));
      }

      rsprintf("</td>\n");
   }

   if (getcfg(lbs->name, "Quick filter", str)) {
      rsprintf("<td class=\"menu2b\">\n");
      n = strbreak(str, list, MAX_N_LIST);

      for (index = 0; index < n; index++) {
         if (equal_ustring(list[index], loc("Date"))) {
            i = atoi(getparam("last"));

            rsprintf("<input type=submit value=\"%s\">&nbsp;\n", loc("Show last"));

            rsprintf("<select name=last onChange=\"document.form1.submit()\">\n");

            rsprintf("<option value=\"_all_\">%s\n", loc("All entries"));

            if (i == 1)
               rsprintf("<option selected value=1>%s\n", loc("Day"));
            else
               rsprintf("<option value=1>%s\n", loc("Day"));
            if (i == 7)
               rsprintf("<option selected value=7>%s\n", loc("Week"));
            else
               rsprintf("<option value=7>%s\n", loc("Week"));
            if (i == 31)
               rsprintf("<option selected value=31>%s\n", loc("Month"));
            else
               rsprintf("<option value=31>%s\n", loc("Month"));
            if (i == 92)
               rsprintf("<option selected value=92>3 %s\n", loc("Months"));
            else
               rsprintf("<option value=92>3 %s\n", loc("Months"));
            if (i == 182)
               rsprintf("<option selected value=182>6 %s\n", loc("Months"));
            else
               rsprintf("<option value=182>6 %s\n", loc("Months"));
            if (i == 364)
               rsprintf("<option selected value=364>%s\n", loc("Year"));
            else
               rsprintf("<option value=364>%s\n", loc("Year"));

            rsprintf("</select> \n");
         } else {
            rsprintf("<input type=submit value=\"%s:\">&nbsp;\n", list[index]);

            for (i = 0; i < MAX_N_ATTR; i++)
               if (equal_ustring(attr_list[i], list[index]))
                  break;

            if (attr_options[i][0][0] == 0) {
               rsprintf
                   ("<input type=text onChange=\"document.form1.submit()\" name=\"%s\" value=\"%s\">\n",
                    list[index], getparam(list[index]));
            } else {
               rsprintf("<select name=\"%s\" onChange=\"document.form1.submit()\">\n",
                        list[index]);

               rsprintf("<option value=\"_all_\">%s\n", loc("All entries"));

               if (i < MAX_N_ATTR) {
                  for (j = 0; j < MAX_N_LIST && attr_options[i][j][0]; j++) {
                     comment[0] = 0;
                     if (attr_flags[i] & AF_ICON) {
                        sprintf(str, "Icon comment %s", attr_options[i][j]);
                        getcfg(lbs->name, str, comment);
                     }

                     strcpy(option, attr_options[i][j]);
                     if (strchr(option, '{'))
                        *strchr(option, '{') = 0;

                     if (comment[0] == 0)
                        strcpy(comment, option);

                     if (isparam(attr_list[i])
                         && equal_ustring(option, getparam(attr_list[i])))
                        rsprintf("<option selected value=\"%s\">%s\n", option, comment);
                     else
                        rsprintf("<option value=\"%s\">%s\n", option, comment);
                  }
               }

               rsprintf("</select> \n");
            }
         }
      }

      rsprintf("&nbsp;<b>%d Entries</b>", n_msg);

      rsprintf("</td>\n");
   }

   rsprintf("</tr></table></td></tr>\n\n");
}

/*------------------------------------------------------------------*/

void show_page_navigation(LOGBOOK * lbs, int n_msg, int page_n, int n_page, BOOL top,
                          BOOL mode_commands, BOOL threaded)
{
   int i, num_pages, skip;
   char ref[256];

   if (!page_n || n_msg <= n_page)
      return;

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu3\">\n");

   rsprintf("%s \n", loc("Goto page"));

   if (page_n > 1) {
      sprintf(ref, "page%d", page_n - 1);
      build_ref(ref, sizeof(ref), "", "");

      rsprintf("<a href=\"%s\">%s</a>&nbsp;&nbsp;", ref, loc("Previous"));
   }

   if (page_n && n_msg > n_page) {
      /* number of pages */
      num_pages = (n_msg - 1) / n_page + 1;
      skip = FALSE;

      for (i = 1; i <= num_pages; i++) {
         sprintf(ref, "page%d", i);
         build_ref(ref, sizeof(ref), "", "");

         if (i <= 3 || (i >= page_n - 1 && i <= page_n + 1)
             || i >= num_pages - 2) {
            if (i > 1 && !skip)
               rsprintf(", \n");

            skip = FALSE;
         } else {
            if (!skip)
               rsprintf("&nbsp;...&nbsp;");

            skip = TRUE;
         }

         if (skip)
            continue;

         if (page_n == i)
            rsprintf("%d", i);
         else
            rsprintf("<a href=\"%s\">%d</a>", ref, i);

         /*
            if (i == num_pages )
            rsprintf("&nbsp;&nbsp;\n");
            else
            rsprintf(", ");
          */
      }

      rsprintf("&nbsp;&nbsp;\n");
   }

   if (page_n != -1 && n_page < n_msg && page_n * n_page < n_msg) {
      sprintf(ref, "page%d", page_n + 1);
      build_ref(ref, sizeof(ref), "", "");

      rsprintf("<a href=\"%s\">%s</a>&nbsp;&nbsp;", ref, loc("Next"));
   }

   if (page_n != -1 && n_page < n_msg) {
      sprintf(ref, "page");
      build_ref(ref, sizeof(ref), "", "");

      rsprintf("<a href=\"%s\">%s</a>\n", ref, loc("All"));
   }

   rsprintf("</span></td></tr>\n");
}

/*------------------------------------------------------------------*/

void show_select_navigation(LOGBOOK * lbs)
{
   int i, n_log;
   char str[NAME_LENGTH];
   char lbk_list[MAX_N_LIST][NAME_LENGTH];

   rsprintf("<tr><td class=\"menuframe\"><span class=\"menu4\">\n");

   rsprintf("<script language=\"JavaScript\" type=\"text/javascript\">\n");
   rsprintf("<!--\n");
   rsprintf("function ToggleAll()\n");
   rsprintf("  {\n");
   rsprintf("  for (var i = 0; i < document.form1.elements.length; i++)\n");
   rsprintf("    {\n");
   rsprintf("    if( document.form1.elements[i].type == 'checkbox' )\n");
   rsprintf
       ("      document.form1.elements[i].checked = !(document.form1.elements[i].checked);\n");
   rsprintf("    }\n");
   rsprintf("  }\n");
   rsprintf("//-->\n");
   rsprintf("</script>\n");

   rsprintf("%s:&nbsp;\n", loc("Selected entries"));

   rsprintf("<input type=button value=\"%s\" onClick=\"ToggleAll();\">\n",
            loc("Toggle all"));

   if (!getcfg(lbs->name, "Menu commands", str) || strstr(str, "Delete")) {
      rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Delete"));
   }

   if (getcfg(lbs->name, "Menu commands", str) && strstr(str, "Copy to")) {
      rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Copy to"));
      rsprintf("<select name=destc>\n");

      if (getcfg(lbs->name, "Copy to", str)) {
         n_log = strbreak(str, lbk_list, MAX_N_LIST);

         for (i = 0; i < n_log; i++)
            rsprintf("<option value=\"%s\">%s\n", lbk_list[i], lbk_list[i]);
      } else {
         for (i = 0;; i++) {
            if (!enumgrp(i, str))
               break;

            if (!is_logbook(str))
               continue;

            if (equal_ustring(str, lbs->name))
               continue;

            rsprintf("<option value=\"%s\">%s\n", str, str);
         }
      }
      rsprintf("</select>\n");
   }

   if (getcfg(lbs->name, "Menu commands", str) && strstr(str, "Move to")) {
      rsprintf("<input type=submit name=cmd value=\"%s\">\n", loc("Move to"));
      rsprintf("<select name=destm>\n");

      if (getcfg(lbs->name, "Move to", str)) {
         n_log = strbreak(str, lbk_list, MAX_N_LIST);

         for (i = 0; i < n_log; i++)
            rsprintf("<option value=\"%s\">%s\n", lbk_list[i], lbk_list[i]);
      } else {
         for (i = 0;; i++) {
            if (!enumgrp(i, str))
               break;

            if (!is_logbook(str))
               continue;

            if (equal_ustring(str, lbs->name))
               continue;

            rsprintf("<option value=\"%s\">%s\n", str, str);
         }
      }
      rsprintf("</select>\n");
   }


   rsprintf("</span></td></tr>\n\n");
}

/*------------------------------------------------------------------*/

void show_elog_list(LOGBOOK * lbs, INT past_n, INT last_n, INT page_n)
{
   int i, j, n, index, size, status, d1, m1, y1, d2, m2, y2, n_line;
   int current_year, current_month, current_day, printable, n_logbook,
       n_display, reverse, n_attr_disp, total_n_msg, n_msg, search_all, message_id,
       n_page, i_start, i_stop, in_reply_to_id;
   char date[80], attrib[MAX_N_ATTR][NAME_LENGTH], disp_attr[MAX_N_ATTR + 4][NAME_LENGTH],
       list[10000], *text, *text1, *text2, in_reply_to[80], reply_to[MAX_REPLY_TO * 10],
       attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH], encoding[80], locked_by[256];
   char str[NAME_LENGTH], ref[256], img[80], comment[NAME_LENGTH];
   char mode[80];
   char menu_str[1000], menu_item[MAX_N_LIST][NAME_LENGTH];
   char *p, *pt, *pt1, *pt2;
   BOOL show_attachments, threaded, csv, mode_commands, expand, filtering, disp_filter;
   time_t ltime, ltime_start, ltime_end, now;
   struct tm tms, *ptms;
   MSG_LIST *msg_list;
   char slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH];
   LOGBOOK *lbs_cur;

   /* redirect if enpty parameters */
   if (strstr(_cmdline, "=&")) {
      while (pt1 = strstr(_cmdline, "=&")) {
         pt2 = pt1 + 2;
         while (*pt1 != '&' && *pt1 != '?')
            pt1--;
         strcpy(pt1 + 1, pt2);
      }
      if (_cmdline[strlen(_cmdline) - 1] == '=') {
         pt1 = _cmdline + strlen(_cmdline) - 1;
         while (*pt1 != '&' && *pt1 != '?')
            *pt1-- = 0;
         *pt1 = 0;
      }
      /* add reverse=0 if not present */
      if (strstr(_cmdline, "reverse=") == NULL && getcfg(lbs->name, "Reverse sort", str)
          && atoi(str) == 1) {
         if (strchr(_cmdline, '?'))
            strlcat(_cmdline, "&reverse=0", sizeof(_cmdline));
         else
            strlcat(_cmdline, "?reverse=0", sizeof(_cmdline));
      }
      redirect(lbs, _cmdline);
      return;
   }

   /* redirect "go" command */
   if (isparam("lastcmd"))      //## and not copy to / move to / delete ...
   {
      strlcpy(str, getparam("lastcmd"), sizeof(str));
      url_decode(str);

      /* subsitute "last" in command line from new parameter */
      if (isparam("last")) {
         if (equal_ustring(getparam("last"), "_all_"))
            subst_param(str, sizeof(str), "last", "");
         else
            subst_param(str, sizeof(str), "last", getparam("last"));
      }

      /* subsitute attributes in command line from new parameter */
      for (i = 0; i < MAX_N_ATTR; i++)
         if (isparam(attr_list[i])) {
            if (equal_ustring(getparam(attr_list[i]), "_all_"))
               subst_param(str, sizeof(str), attr_list[i], "");
            else
               subst_param(str, sizeof(str), attr_list[i], getparam(attr_list[i]));
         }

      redirect(lbs, str);
      return;
   }

   /* remove remaining "_all_" in parameters */
   if (equal_ustring(getparam("last"), "_all_")) {
      strlcpy(str, _cmdline, sizeof(str));
      subst_param(str, sizeof(str), "last", "");
      redirect(lbs, str);
      return;
   }
   for (i = 0; i < MAX_N_ATTR; i++)
      if (equal_ustring(getparam(attr_list[i]), "_all_")) {
         strlcpy(str, _cmdline, sizeof(str));
         subst_param(str, sizeof(str), attr_list[i], "");
         redirect(lbs, str);
         return;
      }

   printable = atoi(getparam("Printable"));

   /* in printable mode, display all pages */
   if (printable)
      page_n = -1;

   if (*getparam("Reverse"))
      reverse = atoi(getparam("Reverse"));
   else {
      reverse = 0;
      if (getcfg(lbs->name, "Reverse sort", str))
         reverse = atoi(str);
   }

   /* default mode */
   strcpy(mode, "Summary");
   show_attachments = FALSE;

   /* for page display, get mode from config file */
   if (past_n || last_n || page_n) {
      if (getcfg(lbs->name, "Display Mode", str))
         strcpy(mode, str);
      if (*getparam("mode"))
         strcpy(mode, getparam("mode"));
   } else {
      /* for find result, get mode from find form */
      strcpy(mode, getparam("mode"));
      if (mode[0] == 0)
         strcpy(mode, "Full");
   }

   threaded = equal_ustring(mode, "threaded");
   csv = equal_ustring(mode, "CSV");

   if (csv) {
      page_n = -1;              /* display all pages */
      show_attachments = FALSE; /* hide attachments */
   }

   /* supersede mode if in parameter */
   if (*getparam("attach"))
      show_attachments = (*getparam("attach") > 0);

   /*---- convert dates to ltime ----*/

   time(&now);
   ptms = localtime(&now);
   current_year = ptms->tm_year + 1900;
   current_month = ptms->tm_mon + 1;
   current_day = ptms->tm_mday;

   ltime_end = ltime_start = 0;

   if (!past_n && !last_n) {
      if (*getparam("m1") || *getparam("y1") || *getparam("d1")) {
         /* if year not given, use current year */
         if (!*getparam("y1"))
            y1 = current_year;
         else
            y1 = atoi(getparam("y1"));
         if (y1 < 1970 || y1 > current_year) {
            sprintf(str, "Error: Year %s out of range", getparam("y1"));
            show_error(str);
            return;
         }

         /* if month not given, use current month */
         if (*getparam("m1")) {
            m1 = atoi(getparam("m1"));
         } else
            m1 = current_month;

         /* if day not given, use 1 */
         if (*getparam("d1"))
            d1 = atoi(getparam("d1"));
         else
            d1 = 1;

         memset(&tms, 0, sizeof(struct tm));
         tms.tm_year = y1 - 1900;
         tms.tm_mon = m1 - 1;
         tms.tm_mday = d1;
         tms.tm_hour = 0;

         if (tms.tm_year < 90)
            tms.tm_year += 100;
         ltime_start = mktime(&tms);
      }

      if (*getparam("m2") || *getparam("y2") || *getparam("d2")) {
         /* if year not give, use current year */
         if (*getparam("y2"))
            y2 = atoi(getparam("y2"));
         else
            y2 = current_year;

         if (y2 < 1970 || y2 > current_year) {
            sprintf(date, "%d", y2);
            sprintf(str, "Error: Year %s out of range", date);
            show_error(str);
            return;
         }

         /* if month not given, use current month */
         if (*getparam("m2")) {
            m2 = atoi(getparam("m2"));
         } else
            m2 = current_month;

         /* if day not given, use last day of month */
         if (*getparam("d2"))
            d2 = atoi(getparam("d2"));
         else {
            memset(&tms, 0, sizeof(struct tm));
            tms.tm_year = y2 - 1900;
            tms.tm_mon = m2 - 1 + 1;
            tms.tm_mday = 1;
            tms.tm_hour = 12;

            if (tms.tm_year < 90)
               tms.tm_year += 100;
            ltime = mktime(&tms);
            ltime -= 3600 * 24;
            memcpy(&tms, localtime(&ltime), sizeof(struct tm));
            d2 = tms.tm_mday;
         }

         memset(&tms, 0, sizeof(struct tm));
         tms.tm_year = y2 - 1900;
         tms.tm_mon = m2 - 1;
         tms.tm_mday = d2;
         tms.tm_hour = 0;
         tms.tm_min = 0;
         tms.tm_sec = 0;

         if (tms.tm_year < 90)
            tms.tm_year += 100;
         ltime_end = mktime(&tms);

         /* end time is first second of next day */
         ltime_end += 3600 * 24;

         memcpy(&tms, localtime(&ltime_end), sizeof(struct tm));
         y2 = tms.tm_year + 1900;
         m2 = tms.tm_mon + 1;
         d2 = tms.tm_mday;
      }
   }

   if (ltime_start && ltime_end && ltime_start > ltime_end) {
      show_error(loc("Error: start date after end date"));
      return;
   }

   /*---- assemble message list ----*/

   /* check for search all */
   search_all = atoi(getparam("all"));

   if (getcfg(lbs->name, "Search all logbooks", str) && atoi(str) == 0)
      search_all = 0;

   n_msg = 0;
   n_display = 0;
   if (search_all) {
      /* count logbooks */
      for (n_logbook = 0;; n_logbook++) {
         if (!lb_list[n_logbook].name[0])
            break;

         if (lbs->top_group[0]
             && !equal_ustring(lbs->top_group, lb_list[n_logbook].top_group))
            continue;

         if (isparam("unm")
             && !check_login_user(&lb_list[n_logbook], getparam("unm")))
            continue;

         n_msg += *lb_list[n_logbook].n_el_index;
      }
   } else {
      n_logbook = 1;
      n_msg = *lbs->n_el_index;
   }

   msg_list = malloc(sizeof(MSG_LIST) * n_msg);

   lbs_cur = lbs;
   for (i = n = 0; i < n_logbook; i++) {
      if (search_all)
         lbs_cur = &lb_list[i];

      if (lbs->top_group[0] && !equal_ustring(lbs->top_group, lbs_cur->top_group))
         continue;

      if (isparam("unm") && !check_login_user(lbs_cur, getparam("unm")))
         continue;

      for (j = 0; j < *lbs_cur->n_el_index; j++) {
         msg_list[n].lbs = lbs_cur;
         msg_list[n].index = j;
         sprintf(msg_list[n].string, "%010d", lbs_cur->el_index[j].file_time);
         msg_list[n].in_reply_to = lbs_cur->el_index[j].in_reply_to;
         n++;
      }
   }

   /*---- apply start/end date cut ----*/

   if (past_n)
      ltime_start = now - 3600 * 24 * past_n;

   if (last_n && last_n < n_msg) {
      for (i = n_msg - last_n - 1; i >= 0; i--)
         msg_list[i].lbs = NULL;
   }

   if (ltime_start) {
      for (i = 0; i < n_msg; i++)
         if (msg_list[i].lbs
             && msg_list[i].lbs->el_index[msg_list[i].index].file_time < ltime_start)
            msg_list[i].lbs = NULL;
   }

   if (ltime_end) {
      for (i = 0; i < n_msg; i++)
         if (msg_list[i].lbs
             && msg_list[i].lbs->el_index[msg_list[i].index].file_time > ltime_end)
            msg_list[i].lbs = NULL;
   }

   if (isparam("last")) {
      n = atoi(getparam("last"));

      if (n > 0) {
         for (i = 0; i < n_msg; i++)
            if (msg_list[i].lbs
                && msg_list[i].lbs->el_index[msg_list[i].index].file_time <
                now - 3600 * 24 * n)
               msg_list[i].lbs = NULL;
      }
   }

   /*---- filter message list ----*/

   filtering = FALSE;

   for (i = 0; i < lbs->n_attr; i++) {
      /* check if attribute filter */
      if (*getparam(attr_list[i]))
         break;

      /* check if sort by attribute */
      if (equal_ustring(getparam("sort"), attr_list[i])
          || equal_ustring(getparam("rsort"), attr_list[i]))
         break;
   }

   /* turn on filtering if found */
   if (i < lbs->n_attr)
      filtering = TRUE;

   if (*getparam("subtext"))
      filtering = TRUE;

   text = malloc(TEXT_SIZE);
   text1 = malloc(TEXT_SIZE);
   text2 = malloc(TEXT_SIZE);
   if (text2 == NULL) {
      show_error("Out of memory");
      return;
   }

   /* do filtering */
   for (index = 0; index < n_msg; index++) {
      if (!msg_list[index].lbs)
         continue;

      /* retrieve message */
      size = TEXT_SIZE;
      message_id = msg_list[index].lbs->el_index[msg_list[index].index].message_id;
      in_reply_to_id = msg_list[index].lbs->el_index[msg_list[index].index].in_reply_to;

      if (filtering) {
         status = el_retrieve(msg_list[index].lbs, message_id,
                              date, attr_list, attrib, lbs->n_attr,
                              text, &size, in_reply_to, reply_to, attachment, encoding,
                              locked_by);
         if (status != EL_SUCCESS)
            break;
      }

      for (i = 0; i < lbs->n_attr; i++) {
         if (*getparam(attr_list[i])) {
            strcpy(str, getparam(attr_list[i]));

            /* if value starts with '$', substitute it */
            if (str[0] == '$') {
               j = build_subst_list(lbs, slist, svalue, attrib);
               strsubst(str, slist, svalue, j);
               setparam(attr_list[i], str);
            }

            for (j = 0; j < (int) strlen(str); j++)
               str[j] = toupper(str[j]);
            str[j] = 0;
            for (j = 0; j < (int) strlen(attrib[i]); j++)
               text1[j] = toupper(attrib[i][j]);
            text1[j] = 0;

            if (strstr(text1, str) == NULL)
               break;
         }
      }
      if (i < lbs->n_attr) {
         msg_list[index].lbs = NULL;
         continue;
      }

      if (*getparam("subtext")) {
         strcpy(str, getparam("subtext"));
         for (i = 0; i < (int) strlen(str); i++)
            str[i] = toupper(str[i]);
         str[i] = 0;
         for (i = 0; i < (int) strlen(text); i++)
            text1[i] = toupper(text[i]);
         text1[i] = 0;

         if (atoi(getparam("sall")) && strstr(text1, str) == NULL) {
            /* search text in attributes */
            for (i = 0; i < lbs->n_attr; i++) {
               for (j = 0; j < (int) strlen(attrib[i]); j++)
                  text1[j] = toupper(attrib[i][j]);
               text1[j] = 0;

               if (strstr(text1, str) != NULL)
                  break;
            }

            if (i == lbs->n_attr) {
               msg_list[index].lbs = NULL;
               continue;
            }
         } else if (strstr(text1, str) == NULL) {
            msg_list[index].lbs = NULL;
            continue;
         }
      }

      /* in threaded mode, find message head */
      if (threaded && in_reply_to_id) {
         do {
            message_id = in_reply_to_id;

            /* search index of message */
            for (i = 0; i < *msg_list[index].lbs->n_el_index; i++)
               if (msg_list[index].lbs->el_index[i].message_id == message_id)
                  break;

            /* stop if not found */
            if (i == *msg_list[index].lbs->n_el_index)
               break;

            in_reply_to_id = msg_list[index].lbs->el_index[i].in_reply_to;

         } while (in_reply_to_id);

         /* if head not found, skip message */
         if (i == *msg_list[index].lbs->n_el_index) {
            msg_list[index].lbs = NULL;
            continue;
         }

         /* check if message head already in list */
         for (j = 0; j < index; j++)
            if (msg_list[j].lbs == msg_list[index].lbs && msg_list[j].index == i)
               break;

         if (j < index) {
            /* set date from current message, if later */
            if (strcmp(msg_list[j].string, msg_list[index].string) < 0)
               strcpy(msg_list[j].string, msg_list[index].string);

            msg_list[index].lbs = NULL; // delete current message
            continue;
         } else {
            msg_list[index].index = i;  // replace current message with message head
         }
      }

      /* add attribute for sorting */
      for (i = 0; i < lbs->n_attr; i++) {
         if (equal_ustring(getparam("sort"), attr_list[i])
             || equal_ustring(getparam("rsort"), attr_list[i])) {
            strlcpy(msg_list[index].string, attrib[i], 256);
         }

         if (equal_ustring(getparam("sort"), loc("ID"))
             || equal_ustring(getparam("rsort"), loc("ID"))) {
            sprintf(msg_list[index].string, "%08d", message_id);
         }

         if (equal_ustring(getparam("sort"), loc("Logbook"))
             || equal_ustring(getparam("rsort"), loc("Logbook"))) {
            strlcpy(msg_list[index].string, msg_list[index].lbs->name, 256);
         }
      }

      if (isparam("rsort"))
         reverse = 1;

      if (isparam("sort"))
         reverse = 0;
   }

   /*---- remove duplicate messages ----*/

   for (i = 0; i < n_msg; i++)
      for (j = i + 1; j < n_msg; j++)
         if (msg_list[i].lbs == msg_list[j].lbs && msg_list[i].index == msg_list[j].index) {
            msg_list[i].lbs = NULL;
            break;
         }

   /*---- compact messasges ----*/

   total_n_msg = n_msg;

   for (i = j = 0; i < n_msg; i++)
      if (msg_list[i].lbs)
         memcpy(&msg_list[j++], &msg_list[i], sizeof(MSG_LIST));
   n_msg = j;

   /*---- sort messasges ----*/

   qsort(msg_list, n_msg, sizeof(MSG_LIST), reverse ? msg_compare_reverse : msg_compare);

   /*---- number of messages per page ----*/

   n_page = 1000000;
   i_start = 0;
   i_stop = n_msg - 1;
   if (page_n) {
      if (getcfg(lbs->name, "Entries per page", str))
         n_page = atoi(str);
      else
         n_page = 20;
      if (isparam("npp"))
         n_page = atoi(getparam("npp"));

      if (page_n != -1) {
         i_start = (page_n - 1) * n_page;
         i_stop = i_start + n_page - 1;

         if (i_start >= n_msg && n_msg > 0) {
            page_n = 1;
            i_start = 0;
         }

         if (i_stop >= n_msg)
            i_stop = n_msg - 1;
      }
   }

   /*---- header ----*/

   if (getcfg(lbs->name, "Summary Page Title", str)) {
      i = build_subst_list(lbs, slist, svalue, NULL);
      strsubst(str, slist, svalue, i);
   } else
      sprintf(str, "ELOG %s", lbs->name);

   if (csv) {

      /* no menus and tables */
      show_plain_header(0);

      for (i = 0; i < lbs->n_attr; i++) {
         strlcpy(str, attr_list[i], sizeof(str));
         while (strchr(str, '"'))
            *strchr(str, '"') = '\'';
         rsprintf("\"%s\"", str);
         if (i < lbs->n_attr - 1)
            rsprintf(",");
         else
            rsprintf("\r\n");
      }

   } else {

      show_standard_header(lbs, TRUE, str, NULL);

      /*---- title ----*/

      strcpy(str, ", ");
      if (past_n == 1)
         strcat(str, loc("Last day"));
      else if (past_n > 1)
         sprintf(str + strlen(str), loc("Last %d days"), past_n);
      else if (last_n)
         sprintf(str + strlen(str), loc("Last %d entries"), last_n);
      else if (page_n == -1)
         sprintf(str + strlen(str), loc("all entries"));
      else if (page_n)
         sprintf(str + strlen(str), loc("Page %d of %d"), page_n,
                 (n_msg - 1) / n_page + 1);
      if (strlen(str) == 2)
         str[0] = 0;

      if (printable)
         show_standard_title(lbs->name, str, 1);
      else
         show_standard_title(lbs->name, str, 0);

      /*---- menu buttons ----*/

      if (!printable) {
         rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

         /* current command line for select command */
         strcpy(str, getparam("cmdline"));

         /* remove select switch */
         if (strstr(str, "select=1")) {
            *strstr(str, "select=1") = 0;
            if (strlen(str) > 1
                && (str[strlen(str) - 1] == '&' || str[strlen(str) - 1] == '?'))
               str[strlen(str) - 1] = 0;
         }

         /* store current command line as hidden parameter for page navigation */
         if (str[0] && !equal_ustring(str, "?")) {
            rsprintf("<input type=hidden name=lastcmd value=\"%s\">\n", str);
         }

         if (!getcfg(lbs->name, "Guest Find menu commands", menu_str)
             || *getparam("unm") != 0)
            getcfg(lbs->name, "Find menu commands", menu_str);

         /* default menu commands */
         if (menu_str[0] == 0) {
            strcpy(menu_str, "New, Find, Select, ");

            if (getcfg(lbs->name, "Password file", str))
               strcat(menu_str, "Config, Logout, ");
            else
               strcat(menu_str, "Config, ");

            if (getcfg(lbs->name, "Mirror server", str))
               strcat(menu_str, "Synchronize, ");

            strcat(menu_str, "Last x, Help");
         }

         n = strbreak(menu_str, menu_item, MAX_N_LIST);

         for (i = 0; i < n; i++) {
            if (is_user_allowed(lbs, menu_item[i])) {
               if (equal_ustring(menu_item[i], "Last x")) {
                  if (past_n) {
                     sprintf(str, loc("Last %d days"), past_n * 2);
                     rsprintf("&nbsp;<a href=\"past%d?mode=%s\">%s</a>&nbsp;|\n",
                              past_n * 2, mode, str);
                  }

                  if (last_n) {
                     sprintf(str, loc("Last %d entries"), last_n * 2);
                     rsprintf("&nbsp;<a href=\"last%d?mode=%s\">%s</a>&nbsp;|\n",
                              last_n * 2, mode, str);
                  }
               } else if (equal_ustring(menu_item[i], "Select")) {
                  strcpy(str, getparam("cmdline"));
                  if (atoi(getparam("select")) == 1) {
                     /* remove select switch */
                     if (strstr(str, "select=1")) {
                        *strstr(str, "select=1") = 0;
                        if (strlen(str) > 1
                            && (str[strlen(str) - 1] == '&'
                                || str[strlen(str) - 1] == '?'))
                           str[strlen(str) - 1] = 0;
                     }
                  } else {
                     /* add select switch */
                     if (strchr(str, '?'))
                        strcat(str, "&select=1");
                     else
                        strcat(str, "?select=1");
                  }
                  rsprintf("&nbsp;<a href=\"%s\">%s</a>&nbsp;|\n", str, loc("Select"));
               } else {
                  strcpy(str, loc(menu_item[i]));
                  url_encode(str, sizeof(str));

                  if (i < n - 1)
                     rsprintf("&nbsp;<a href=\"?cmd=%s\">%s</a>&nbsp;|\n", str,
                              loc(menu_item[i]));
                  else
                     rsprintf("&nbsp;<a href=\"?cmd=%s\">%s</a>&nbsp;\n", str,
                              loc(menu_item[i]));
               }
            }
         }

         rsprintf("</span></td></tr>\n\n");
      }

      /*---- find menu text ----*/

      if (getcfg(lbs->name, "find menu text", str) && !printable) {
         FILE *f;
         char file_name[256], *buf;

         rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

         /* check if file starts with an absolute directory */
         if (str[0] == DIR_SEPARATOR || str[1] == ':')
            strcpy(file_name, str);
         else {
            strlcpy(file_name, resource_dir, sizeof(file_name));
            strlcat(file_name, str, sizeof(file_name));
         }

         f = fopen(file_name, "rb");
         if (f != NULL) {
            fseek(f, 0, SEEK_END);
            size = TELL(fileno(f));
            fseek(f, 0, SEEK_SET);

            buf = malloc(size + 1);
            fread(buf, 1, size, f);
            buf[size] = 0;
            fclose(f);

            rsputs(buf);

         } else
            rsprintf("<center><b>Error: file <i>\"%s\"</i> not found</b></center>",
                     file_name);

         rsprintf("</span></td></tr>");
      }

      /*---- display filters ----*/

      disp_filter = *getparam("m1") || *getparam("y1") || *getparam("d1")
          || *getparam("m2")
          || *getparam("y2") || *getparam("d2")
          || *getparam("subtext");

      for (i = 0; i < lbs->n_attr; i++)
         if (*getparam(attr_list[i]))
            disp_filter = TRUE;

      if (disp_filter) {
         rsprintf("<tr><td class=\"listframe\">\n");
         rsprintf("<table width=\"100%%\" border=0 cellpadding=0 cellspacing=0>\n");

         if (*getparam("m1") || *getparam("y1") || *getparam("d1")) {


            memset(&tms, 0, sizeof(struct tm));
            tms.tm_year = y1 - 1900;
            tms.tm_mon = m1 - 1;
            tms.tm_mday = d1;
            tms.tm_hour = 12;
            if (tms.tm_year < 90)
               tms.tm_year += 100;
            mktime(&tms);
            strftime(str, sizeof(str), "%#x", &tms);

            rsprintf("<tr><td nowrap width=\"10%%\" class=\"attribname\">%s:</td>",
                     loc("Start date"));
            rsprintf("<td class=\"attribvalue\">%s</td></tr>", str);
         }

         if (*getparam("m2") || *getparam("y2") || *getparam("d2")) {
            /* calculate previous day */
            memset(&tms, 0, sizeof(struct tm));
            tms.tm_year = y2 - 1900;
            tms.tm_mon = m2 - 1;
            tms.tm_mday = d2;
            tms.tm_hour = 12;
            if (tms.tm_year < 90)
               tms.tm_year += 100;
            ltime = mktime(&tms);
            ltime -= 3600 * 24;
            memcpy(&tms, localtime(&ltime), sizeof(struct tm));
            strftime(str, sizeof(str), "%#x", &tms);

            rsprintf("<tr><td nowrap width=\"10%%\" class=\"attribname\">%s:</td>",
                     loc("End date"));

            rsprintf("<td class=\"attribvalue\">%s</td></tr>", str);
         }

         for (i = 0; i < lbs->n_attr; i++) {
            if (*getparam(attr_list[i])) {
               comment[0] = 0;
               if (attr_flags[i] & AF_ICON) {
                  sprintf(str, "Icon comment %s", getparam(attr_list[i]));
                  getcfg(lbs->name, str, comment);
               }

               if (comment[0] == 0)
                  strcpy(comment, getparam(attr_list[i]));

               rsprintf("<tr><td nowrap width=\"10%%\" class=\"attribname\">%s:</td>",
                        attr_list[i]);
               rsprintf("<td class=\"attribvalue\">%s</td></tr>", comment);
            }
         }

         if (*getparam("subtext")) {
            rsprintf("<tr><td nowrap width=\"10%%\" class=\"attribname\">%s:</td>",
                     loc("Text"));
            rsprintf
                ("<td class=\"attribvalue\"><span style=\"color:black;background-color:#ffff66\">%s</span></td></tr>",
                 getparam("subtext"));
         }

         rsprintf("</table></td></tr>\n\n");
      }

      /* get number of summary lines */
      n_line = 3;
      if (getcfg(lbs->name, "Summary lines", str))
         n_line = atoi(str);

      /* get mode commands flag */
      mode_commands = TRUE;
      if (getcfg(lbs->name, "Mode commands", str) && atoi(str) == 0)
         mode_commands = FALSE;

      /*---- page navigation ----*/

      if (!printable) {
         show_page_filters(lbs, n_msg, page_n, n_page, TRUE, mode_commands, threaded);
         show_page_navigation(lbs, n_msg, page_n, n_page, TRUE, mode_commands, threaded);
      }

      /*---- select navigation ----*/

      if (atoi(getparam("select")) == 1)
         show_select_navigation(lbs);

      /*---- table titles ----*/

      /* overall listing table */
      rsprintf("<tr><td><table class=\"listframe\" width=\"100%%\" cellspacing=0>\n");

      size = printable ? 2 : 3;

      list[0] = 0;
      if (!getcfg(lbs->name, "List display", list))     /* new 2.3.10 format */
         getcfg(lbs->name, "Display search", list);     /* old 2.3.9  format */

      if (list[0]) {
         n_attr_disp = strbreak(list, disp_attr, MAX_N_ATTR);
         if (search_all) {
            for (i = n_attr_disp - 1; i >= 0; i--)
               strcpy(disp_attr[i + 1], disp_attr[i]);
            strcpy(disp_attr[0], loc("Logbook"));
            n_attr_disp++;
         }
      } else {
         if (search_all) {
            n_attr_disp = lbs->n_attr + 3;

            strcpy(disp_attr[0], loc("Logbook"));
            strcpy(disp_attr[1], loc("ID"));
            strcpy(disp_attr[2], loc("Date"));
            memcpy(disp_attr + 3, attr_list, sizeof(attr_list));
         } else {
            n_attr_disp = lbs->n_attr + 2;

            strcpy(disp_attr[0], loc("ID"));
            strcpy(disp_attr[1], loc("Date"));
            memcpy(disp_attr + 2, attr_list, sizeof(attr_list));
         }
      }

      if (threaded) {
      } else {
         rsprintf("<tr>\n");

         /* empty title for selection box */
         if (atoi(getparam("select")) == 1)
            rsprintf("<th class=\"listtitle\">&nbsp;</th>\n");

         for (i = 0; i < n_attr_disp; i++) {
            /* assemble current command line, replace sort statements */
            strcpy(ref, getparam("cmdline"));
            if (strstr(ref, "&sort=")) {
               p = strstr(ref, "&sort=") + 1;
               while (*p && *p != '&')
                  p++;
               strcpy(strstr(ref, "&sort="), p);
            }
            if (strstr(ref, "&rsort=")) {
               p = strstr(ref, "&rsort=") + 1;
               while (*p && *p != '&')
                  p++;
               strcpy(strstr(ref, "&rsort="), p);
            }
            if (strstr(ref, "?sort="))
               *strstr(ref, "?sort=") = 0;
            if (strstr(ref, "?rsort="))
               *strstr(ref, "?rsort=") = 0;

            strcpy(str, disp_attr[i]);
            url_encode(str, sizeof(str));
            if (strcmp(getparam("sort"), disp_attr[i]) == 0) {
               if (strchr(ref, '?'))
                  sprintf(ref + strlen(ref), "&rsort=%s", str);
               else
                  sprintf(ref + strlen(ref), "?rsort=%s", str);
            } else {
               if (strchr(ref, '?'))
                  sprintf(ref + strlen(ref), "&sort=%s", str);
               else
                  sprintf(ref + strlen(ref), "?sort=%s", str);
            }

            img[0] = 0;
            if (strcmp(getparam("sort"), disp_attr[i]) == 0)
               strcpy(img, "<img align=top src=\"up.gif\">");
            else if (strcmp(getparam("rsort"), disp_attr[i]) == 0)
               strcpy(img, "<img align=top src=\"down.gif\">");

            rsprintf("<th class=\"listtitle\"><a href=\"%s\">%s</a>%s</th>\n", ref,
                     disp_attr[i], img);
         }

         if (!equal_ustring(mode, "Full") && n_line > 0)
            rsprintf("<th class=\"listtitle\">%s</th>\n", loc("Text"));

         rsprintf("</tr>\n\n");
      }
   }                            /* if (!csv) */

   /*---- display message list ----*/

   for (index = i_start; index <= i_stop; index++) {
      size = TEXT_SIZE;
      message_id = msg_list[index].lbs->el_index[msg_list[index].index].message_id;

      status = el_retrieve(msg_list[index].lbs, message_id,
                           date, attr_list, attrib, lbs->n_attr,
                           text, &size, in_reply_to, reply_to, attachment, encoding,
                           locked_by);
      if (status != EL_SUCCESS)
         break;

      if (csv) {

         for (i = 0; i < lbs->n_attr; i++) {
            strlcpy(str, attrib[i], sizeof(str));
            while (strchr(str, '"'))
               *strchr(str, '"') = '\'';
            rsprintf("\"%s\"", str);
            if (i < lbs->n_attr - 1)
               rsprintf(",");
            else
               rsprintf("\r\n");
         }

      } else {

         /*---- add highlighting for searched subtext ----*/

         if (*getparam("subtext")) {
            strcpy(str, getparam("subtext"));
            for (i = 0; i < (int) strlen(str); i++)
               str[i] = toupper(str[i]);

            for (i = 0; i < (int) strlen(text); i++)
               text1[i] = toupper(text[i]);
            text1[i] = 0;

            text2[0] = 0;
            pt = text;          /* original text */
            pt1 = text1;        /* upper-case text */
            pt2 = text2;        /* text with inserted coloring */
            do {
               p = strstr(pt1, str);
               size = (int) (p - pt1);
               if (p != NULL) {
                  pt1 = p + strlen(str);

                  /* copy first part original text */
                  memcpy(pt2, pt, size);
                  pt2 += size;
                  pt += size;

                  /* add coloring 1st part */

                  /* here: \001='<', \002='>', /003='"', and \004=' ' */
                  /* see also rsputs2(char* ) */

                  if (equal_ustring(encoding, "plain")
                      || !equal_ustring(mode, "Full"))
                     strcpy(pt2,
                            "\001B\004style=\003color:black;background-color:#ffff66\003\002");
                  else
                     strcpy(pt2, "<B style=\"color:black;background-color:#ffff66\">");

                  pt2 += strlen(pt2);

                  /* copy origial search text */
                  memcpy(pt2, pt, strlen(str));
                  pt2 += strlen(str);
                  pt += strlen(str);

                  /* add coloring 2nd part */
                  if (equal_ustring(encoding, "plain")
                      || !equal_ustring(mode, "Full"))
                     strcpy(pt2, "\001/B\002");
                  else
                     strcpy(pt2, "</B>");
                  pt2 += strlen(pt2);
               }
            } while (p != NULL);

            strcpy(pt2, pt);
            strcpy(text, text2);
         }

         /*---- display line ----*/

         expand = 1;
         if (threaded) {
            if (getcfg(lbs->name, "Expand default", str))
               expand = atoi(str);

            if (isparam("expand"))
               expand = atoi(getparam("expand"));
         }

         display_line(msg_list[index].lbs, message_id,
                      index, mode, expand, 0, printable, n_line,
                      show_attachments, date, in_reply_to, reply_to,
                      n_attr_disp, disp_attr, attrib, lbs->n_attr, text,
                      attachment, encoding, atoi(getparam("select")), &n_display,
                      locked_by);

         if (threaded) {
            if (reply_to[0] && expand > 0) {
               p = reply_to;
               do {
                  display_reply(msg_list[index].lbs, atoi(p), printable, expand, n_line,
                                n_attr_disp, disp_attr, 1);

                  while (*p && isdigit(*p))
                     p++;
                  while (*p && (*p == ',' || *p == ' '))
                     p++;
               } while (*p);
            }
         }
      }                         /* if (!csv) */
   }                            /* for() */

   if (!csv) {
      rsprintf("</table>\n");

      if (n_display)
         rsprintf("<input type=hidden name=nsel value=%d>\n", n_display);

      rsprintf("</td></tr>\n");

      if (n_msg == 0)
         rsprintf("<tr><td class=\"errormsg\">%s</td></tr>", loc("No entries found"));

      /*---- page navigation ----*/

      if (!printable)
         show_page_navigation(lbs, n_msg, page_n, n_page, FALSE, FALSE, threaded);

      rsprintf("</table>\n");
      show_bottom_text(lbs);
      rsprintf("</form></body></html>\r\n");
   }

   free(msg_list);
   free(text);
   free(text1);
   free(text2);
}

/*------------------------------------------------------------------*/

int compose_email(LOGBOOK * lbs, char *mail_to, int message_id,
                  char attrib[MAX_N_ATTR][NAME_LENGTH], char *mail_param, int old_mail,
                  char att_file[MAX_ATTACHMENTS][256])
{
   int i, j, k, n, flags, status;
   char str[NAME_LENGTH + 100], str2[256], mail_from[256], *mail_text, smtp_host[256],
       subject[256];
   char slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH];
   char list[MAX_PARAM][NAME_LENGTH], url[256], comment[256];

   if (!getcfg("global", "SMTP host", smtp_host)) {
      show_error(loc("No SMTP host defined in [global] section of configuration file"));
      return 0;
   }

   flags = 63;
   if (getcfg(lbs->name, "Email format", str))
      flags = atoi(str);

   if (getcfg(lbs->name, "Use Email from", mail_from)) {
      j = build_subst_list(lbs, slist, svalue, attrib);
      strsubst(mail_from, slist, svalue, j);
      if (strncmp(mail_from, "mailto:", 7) == 0)
         strcpy(mail_from, mail_from + 7);
   } else
      sprintf(mail_from, "ELog@%s", host_name);

   mail_text = malloc(TEXT_SIZE + 1000);
   mail_text[0] = 0;

   if (flags & 1) {
      if (getcfg(lbs->name, "Use Email heading", str)) {
         if (old_mail) {
            if (!getcfg(lbs->name, "Use Email heading edit", str))
               getcfg(lbs->name, "Use Email heading", str);
         }

         sprintf(mail_text + strlen(mail_text), str);

      } else {
         if (old_mail)
            sprintf(mail_text + strlen(mail_text),
                    loc("A old entry has been updated on %s"), host_name);
         else
            sprintf(mail_text + strlen(mail_text),
                    loc("A new entry has been submitted on %s"), host_name);
      }

      sprintf(mail_text + strlen(mail_text), "\r\n\r\n");
   }

   if (flags & 32)
      sprintf(mail_text + strlen(mail_text), "%s             : %s\r\n", loc("Logbook"),
              lbs->name);

   if (flags & 2) {
      for (j = 0; j < lbs->n_attr; j++) {
         strcpy(str,
                "                                                                       ");
         memcpy(str, attr_list[j], strlen(attr_list[j]));

         comment[0] = 0;
         if (attr_flags[j] & AF_ICON) {
            sprintf(str2, "Icon comment %s", attrib[j]);
            getcfg(lbs->name, str2, comment);
         }
         if (!comment[0])
            strcpy(comment, attrib[j]);

         if (equal_ustring(attr_options[j][0], "boolean"))
            strcpy(comment, atoi(attrib[j]) ? loc("Yes") : loc("No"));

         for (k = strlen(str) - 1; k > 0; k--)
            if (str[k] != ' ')
               break;

         if (k < 20)
            sprintf(str + 20, ": %s\r\n", comment);
         else
            sprintf(str + k + 1, ": %s\r\n", comment);

         strcpy(mail_text + strlen(mail_text), str);
      }
   }

   /* compose subject from attributes */
   if (getcfg(lbs->name, "Use Email Subject", subject)) {
      j = build_subst_list(lbs, slist, svalue, attrib);
      strsubst(subject, slist, svalue, j);
   } else {
      if (old_mail)
         strcpy(subject, "Updated ELOG entry");
      else
         strcpy(subject, "New ELOG entry");
   }

   /* try to get URL from referer */

   if (!getcfg("global", "URL", str)) {
      if (referer[0])
         strcpy(str, referer);
      else {
         if (tcp_port == 80)
            sprintf(str, "http://%s/", host_name);
         else
            sprintf(str, "http://%s:%d/", host_name, tcp_port);
         strcat(str, lbs->name);
         strcat(str, "/");
      }
   } else {
      strlcat(str, lbs->name_enc, sizeof(str));
      strlcat(str, "/", sizeof(str));
   }

   sprintf(url, "%s%d", str, message_id);

   if (flags & 4) {
      sprintf(mail_text + strlen(mail_text), "\r\n%s URL         : %s\r\n",
              loc("Logbook"), url);
   }

   if (flags & 8) {
      if (*getparam("text"))
         sprintf(mail_text + strlen(mail_text),
                 "\r\n=================================\r\n\r\n%s", getparam("text"));
   }

   status = 0;
   if (flags & 16) {
      if (getcfg(lbs->name, "Omit Email to", str) && atoi(str) == 1)
         status =
             sendmail(lbs, smtp_host, mail_from, mail_to, subject, mail_text, FALSE, url,
                      att_file);
      else
         status =
             sendmail(lbs, smtp_host, mail_from, mail_to, subject, mail_text, TRUE, url,
                      att_file);
   } else {
      if (getcfg(lbs->name, "Omit Email to", str) && atoi(str) == 1)
         status =
             sendmail(lbs, smtp_host, mail_from, mail_to, subject, mail_text, FALSE, url,
                      NULL);
      else
         status =
             sendmail(lbs, smtp_host, mail_from, mail_to, subject, mail_text, TRUE, url,
                      NULL);
   }

   if (status < 0) {
      sprintf(str, loc("Error sending Email via <i>\"%s\"</i>"), smtp_host);
      url_encode(str, sizeof(str));
      sprintf(mail_param, "?error=%s", str);
   } else {
      if (!getcfg(lbs->name, "Display email recipients", str) || atoi(str) == 1) {
         if (mail_param[0] == 0)
            strcpy(mail_param, "?");
         else
            strcat(mail_param, "&");

         n = strbreak(mail_to, list, MAX_PARAM);

         if (n < 10) {
            for (i = 0; i < n && i < MAX_PARAM; i++) {
               sprintf(mail_param + strlen(mail_param), "mail%d=%s", i, list[i]);
               if (i < n - 1)
                  strcat(mail_param, "&");
            }
         } else {
            sprintf(str, "%d%%20%s", n, loc("recipients"));
            sprintf(mail_param + strlen(mail_param), "mail0=%s", str);
         }
      }
   }

   free(mail_text);

   return status;
}

/*------------------------------------------------------------------*/

int execute_shell(LOGBOOK * lbs, int message_id, char attrib[MAX_N_ATTR][NAME_LENGTH],
                  char *sh_cmd)
{
   int i;
   char slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH];
   char shell_cmd[1000];

   if (!enable_execute) {
      printf("Shell execution not enabled via -x flag.\n");
      return SUCCESS;
   }

   strlcpy(shell_cmd, sh_cmd, sizeof(shell_cmd));

   i = build_subst_list(lbs, slist, svalue, attrib);

   /* add message id */
   strcpy(slist[i], "Message ID");
   sprintf(svalue[i++], "%d", message_id);

   strsubst(shell_cmd, slist, svalue, i);

   logf(lbs, "SHELL \"%s\"", shell_cmd);

   system(shell_cmd);

   return SUCCESS;
}

/*------------------------------------------------------------------*/

int add_attribute_option(LOGBOOK * lbs, char *attrname, char *attrvalue)
{
   int fh, i, length;
   char str[NAME_LENGTH], *buf, *buf2, *p1, *p2, *p3;

   fh = open(config_file, O_RDWR | O_BINARY, 644);
   if (fh < 0) {
      sprintf(str, loc("Cannot open file <b>%s</b>"), config_file);
      strcat(str, ": ");
      strcat(str, strerror(errno));
      show_error(str);
      return 0;
   }

   /* read previous contents */
   length = lseek(fh, 0, SEEK_END);
   lseek(fh, 0, SEEK_SET);
   buf = malloc(length + strlen(attrvalue) + 3);
   assert(buf);
   read(fh, buf, length);
   buf[length] = 0;

   /* find location of options */
   sprintf(str, "Options %s", attrname);
   p1 = (char *) find_param(buf, lbs->name, str);
   p2 = strchr(p1, '\n');
   if (*(p2 - 1) == '\r')
      p2--;

   /* save tail */
   if (p2) {
      buf2 = malloc(strlen(p2) + 1);
      assert(buf2);
      strlcpy(buf2, p2, strlen(p2) + 1);
   }

   /* add option */
   p3 = strchr(p1, '\n');
   if (p3 == NULL)
      p3 = p1 + strlen(p1);
   while (*(p3 - 1) == '\n' || *(p3 - 1) == '\r' || *(p3 - 1) == ' ' || *(p3 - 1) == '\t')
      p3--;

   sprintf(p3, ", %s", attrvalue);
   if (p2) {
      strlcat(buf, buf2, length + strlen(attrvalue) + 3);
      free(buf2);
   }

   lseek(fh, 0, SEEK_SET);
   i = write(fh, buf, strlen(buf));
   if (i < (int) strlen(buf)) {
      sprintf(str, loc("Cannot write to <b>%s</b>"), config_file);
      strcat(str, ": ");
      strcat(str, strerror(errno));
      show_error(str);
      close(fh);
      free(buf);
      return 0;
   }
#ifdef _MSC_VER
   chsize(fh, TELL(fh));
#else
   ftruncate(fh, TELL(fh));
#endif

   close(fh);
   free(buf);

   /* force re-read of config file */
   check_config();

   return 1;
}

/*------------------------------------------------------------------*/

void submit_elog(LOGBOOK * lbs)
{
   char str[1000], str2[1000], file_name[256], error[1000], date[80],
       mail_list[MAX_N_LIST][NAME_LENGTH], list[10000],
       attrib[MAX_N_ATTR][NAME_LENGTH], subst_str[MAX_PATH_LENGTH],
       in_reply_to[80], reply_to[MAX_REPLY_TO * 10], user[256], user_email[256],
       email_notify[256], mail_param[1000], *mail_to, att_file[MAX_ATTACHMENTS][256],
       slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH],
       ua[NAME_LENGTH];
   int i, j, n, missing, first, index, mindex, suppress, message_id, resubmit_orig,
       mail_to_size;
   BOOL bedit;

   /* check for required attributs */
   missing = 0;
   for (i = 0; i < lbs->n_attr; i++) {
      strcpy(ua, attr_list[i]);
      btou(ua);

      if (attr_flags[i] & AF_REQUIRED) {
         if ((attr_flags[i] & AF_MULTI) == 0 && *getparam(ua) == 0) {
            missing = 1;
            break;
         }
         if ((attr_flags[i] & AF_MULTI)) {
            for (j = 0; j < MAX_N_LIST; j++) {
               sprintf(str, "%s_%d", ua, j);
               if (getparam(str) && *getparam(str))
                  break;
            }

            if (j == MAX_N_LIST) {
               missing = 1;
               break;
            }
         }
      }
   }

   if (missing) {
      sprintf(error, "<i>");
      sprintf(error + strlen(error), loc("Error: Attribute <b>%s</b> not supplied"),
              attr_list[i]);
      sprintf(error + strlen(error), ".</i><p>\n");
      sprintf(error + strlen(error), loc("Please go back and enter the <b>%s</b> field"),
              attr_list[i]);
      strcat(error, ".\n");

      show_error(error);
      return;
   }

   /* check for extended attributs */
   for (i = 0; i < lbs->n_attr; i++) {
      strcpy(ua, attr_list[i]);
      btou(ua);
      if (isparam(ua) && attr_options[i][0][0]) {

         if (equal_ustring(attr_options[i][0], "boolean")) {
            if (atoi(getparam(ua)) != 0 && atoi(getparam(ua)) != 1) {
               sprintf(error,
                       loc("Error: Value <b>%s</b> not allowed for boolean attributes"),
                       getparam(ua));
               show_error(error);
               return;
            }

         } else {

            /* check if option exists */
            for (j = 0; attr_options[i][j][0]; j++)
               if (equal_ustring(attr_options[i][j], getparam(ua)))
                  break;

            /* check if option without {n} exists */
            if (!attr_options[i][j][0]) {
               for (j = 0; attr_options[i][j][0]; j++) {
                  strcpy(str, attr_options[i][j]);
                  if (strchr(str, '{'))
                     *strchr(str, '{') = 0;
                  if (equal_ustring(str, getparam(ua)))
                     break;
               }
            }

            if (!attr_options[i][j][0] && *getparam(ua)) {
               if (attr_flags[i] & AF_EXTENDABLE) {
                  if (!add_attribute_option(lbs, attr_list[i], getparam(ua)))
                     return;
               } else {
                  sprintf(error, loc("Error: Attribute option <b>%s</b> not existing"),
                          getparam(ua));
                  show_error(error);
                  return;
               }
            }
         }
      }
   }

   /* get attachments */
   for (i = 0; i < MAX_ATTACHMENTS; i++) {
      sprintf(str, "attachment%d", i);
      strcpy(att_file[i], getparam(str));
   }

   /* compile substitution list */
   n = build_subst_list(lbs, slist, svalue, NULL);

   /* retrieve attributes */
   for (i = 0; i < lbs->n_attr; i++) {

      strcpy(ua, attr_list[i]);
      btou(ua);

      if (attr_flags[i] & AF_MULTI) {
         attrib[i][0] = 0;
         first = 1;
         for (j = 0; j < MAX_N_LIST; j++) {
            sprintf(str, "%s_%d", ua, j);
            if (getparam(str)) {
               if (*getparam(str)) {
                  if (first)
                     first = 0;
                  else
                     strlcat(attrib[i], " | ", NAME_LENGTH);
                  if (strlen(attrib[i]) + strlen(getparam(str)) < NAME_LENGTH - 2)
                     strlcat(attrib[i], getparam(str), NAME_LENGTH);
                  else
                     break;
               }
            } else
               break;
         }
      } else {
         strlcpy(attrib[i], getparam(ua), NAME_LENGTH);

         /* strip trailing "{...}" */
         if (strchr(attrib[i], '{') && strchr(attrib[i], '}'))
            *strchr(attrib[i], '{') = 0;
      }

      if (!*getparam("edit_id")) {
         sprintf(str, "Subst %s", attr_list[i]);
         if (getcfg(lbs->name, str, subst_str)) {
            strsubst(subst_str, slist, svalue, n);
            strcpy(attrib[i], subst_str);
         }
      }
   }

   message_id = 0;
   reply_to[0] = 0;
   in_reply_to[0] = 0;
   date[0] = 0;
   resubmit_orig = 0;
   bedit = FALSE;

   if (*getparam("edit_id") && *getparam("resubmit")
       && atoi(getparam("resubmit")) == 1) {
      resubmit_orig = atoi(getparam("edit_id"));
      bedit = TRUE;

      /* get old links */
      el_retrieve(lbs, resubmit_orig, NULL, NULL, NULL, 0, NULL, 0, in_reply_to,
                  reply_to, NULL, NULL, NULL);

      /* if not message head, move all preceeding messages */
      /* outcommented, users want only resubmitted message occur at end (see what's new)
         if (in_reply_to[0])
         {
         do
         {
         resubmit_orig = atoi(in_reply_to);
         el_retrieve(lbs, resubmit_orig, NULL, NULL, NULL, 0,
         NULL, 0, in_reply_to, reply_to, NULL, NULL);
         } while (in_reply_to[0]);
         }
       */

      message_id = atoi(getparam("edit_id"));
      strcpy(in_reply_to, "<keep>");
      strcpy(reply_to, "<keep>");
      date[0] = 0;
   } else {
      if (*getparam("edit_id")) {
         bedit = TRUE;
         message_id = atoi(getparam("edit_id"));
         strcpy(in_reply_to, "<keep>");
         strcpy(reply_to, "<keep>");
         strcpy(date, "<keep>");
      } else
         strcpy(in_reply_to, getparam("reply_to"));
   }

   if (_logging_level > 1) {
      if (isparam("edit_id"))
         logf(lbs, "EDIT entry #%d", message_id);
      else
         logf(lbs, "NEW entry #%d", message_id);
   }

   message_id =
       el_submit(lbs, message_id, bedit, date, attr_list, attrib, lbs->n_attr,
                 getparam("text"), in_reply_to, reply_to,
                 *getparam("html") ? "HTML" : "plain", att_file, TRUE, NULL);

   if (message_id <= 0) {
      sprintf(str, loc("New entry cannot be written to directory \"%s\""), lbs->data_dir);
      strcat(str, "\n<p>");
      strcat(str, loc("Please check that it exists and elogd has write access"));
      show_error(str);
      return;
   }

   /* resubmit thread if requested */
   if (resubmit_orig)
      message_id = el_move_message_thread(lbs, resubmit_orig);

   /*---- email notifications ----*/

   suppress = atoi(getparam("suppress"));

   /* check for mail submissions */
   mail_param[0] = 0;
   mail_to = malloc(256);
   mail_to[0] = 0;
   mail_to_size = 256;

   if (suppress) {
      strcpy(mail_param, "?suppress=1");
   } else {
      if (!(*getparam("edit_id")
            && getcfg(lbs->name, "Suppress Email on edit", str)
            && atoi(str) == 1)) {
         /* go throuch "Email xxx" in configuration file */
         for (index = mindex = 0; index <= lbs->n_attr; index++) {

            strcpy(ua, attr_list[index]);
            btou(ua);

            if (index < lbs->n_attr) {
               strcpy(str, "Email ");
               if (strchr(attr_list[index], ' '))
                  sprintf(str + strlen(str), "\"%s\"", attr_list[index]);
               else
                  strlcat(str, attr_list[index], sizeof(str));
               strcat(str, " ");

               if (attr_flags[index] & AF_MULTI) {
                  sprintf(str2, "%s_%d", ua, mindex);

                  mindex++;
                  if (mindex == MAX_N_LIST)
                     mindex = 0;
                  else
                     index--;   /* repeat this loop */
               } else
                  strcpy(str2, ua);

               if (strchr(getparam(str2), ' '))
                  sprintf(str + strlen(str), "\"%s\"", getparam(str2));
               else
                  strlcat(str, getparam(str2), sizeof(str));
            } else
               sprintf(str, "Email ALL");

            if (getcfg(lbs->name, str, list)) {
               n = strbreak(list, mail_list, MAX_N_LIST);

               if (verbose)
                  printf("\n%s to %s\n\n", str, list);

               for (i = 0; i < n; i++) {
                  j = build_subst_list(lbs, slist, svalue, attrib);
                  strsubst(mail_list[i], slist, svalue, j);

                  if ((int) strlen(mail_to) + (int) strlen(mail_list[i]) >= mail_to_size) {
                     mail_to_size += 256;
                     mail_to = realloc(mail_to, mail_to_size);
                  }
                  strcat(mail_to, mail_list[i]);
                  strcat(mail_to, ",");
               }
            }
         }

         if (!getcfg(lbs->name, "Suppress Email to users", str) || atoi(str) == 0) {
            /* go through password file */
            for (index = 0;; index++) {
               if (!enum_user_line(lbs, index, user))
                  break;

               get_user_line(lbs->name, user, NULL, NULL, user_email, email_notify);

               if (email_notify[0]) {
                  /* check if user has access to this logbook */
                  if (!check_login_user(lbs, user))
                     continue;

                  if ((int) strlen(mail_to) + (int) strlen(user_email) >= mail_to_size) {
                     mail_to_size += 256;
                     mail_to = realloc(mail_to, mail_to_size);
                  }
                  strcat(mail_to, user_email);
                  strcat(mail_to, ",");
               }
            }
         }
      }
   }

   if (strlen(mail_to) > 0) {
      mail_to[strlen(mail_to) - 1] = 0; /* strip last ',' */
      if (compose_email
          (lbs, mail_to, message_id, attrib, mail_param, *getparam("edit_id"),
           att_file) == 0)
         return;
   }

   free(mail_to);

   /*---- shell execution ----*/

   if (!atoi(getparam("shell_suppress"))) {
      if (!*getparam("edit_id")) {
         if (getcfg(lbs->name, "Execute new", str))
            execute_shell(lbs, message_id, attrib, str);
      } else {
         if (getcfg(lbs->name, "Execute edit", str))
            execute_shell(lbs, message_id, attrib, str);
      }
   }

   /*---- custom submit page ----*/

   if (getcfg(lbs->name, "Submit page", str)) {
      /* check if file starts with an absolute directory */
      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strcpy(file_name, str);
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }
      send_file_direct(file_name);
      return;
   }

   sprintf(str, "%d%s", message_id, mail_param);
   redirect(lbs, str);
}

/*------------------------------------------------------------------*/

void submit_elog_mirror(LOGBOOK * lbs)
{
   char str[1000], date[80], attrib_value[MAX_N_ATTR][NAME_LENGTH],
       attrib_name[MAX_N_ATTR][NAME_LENGTH], in_reply_to[80], encoding[80],
       reply_to[MAX_REPLY_TO * 10], att_file[MAX_ATTACHMENTS][256], name[NAME_LENGTH],
       value[NAME_LENGTH];
   int i, message_id, n_attr;
   BOOL bedit;

   /* get attachments */
   for (i = 0; i < MAX_ATTACHMENTS; i++) {
      sprintf(str, "attachment%d", i);
      strcpy(att_file[i], getparam(str));
   }

   reply_to[0] = 0;
   in_reply_to[0] = 0;
   date[0] = 0;
   encoding[0] = 0;
   bedit = FALSE;
   n_attr = 0;
   message_id = 0;

   /* retrieve attributes */
   for (i = 0; i < MAX_PARAM; i++) {
      if (enumparam(i, name, value)) {

         if (equal_ustring(name, "mirror_id"))
            message_id = atoi(value);
         else if (equal_ustring(name, "entry_date"))
            strlcpy(date, value, sizeof(date));
         else if (equal_ustring(name, "reply_to"))
            strlcpy(reply_to, value, sizeof(reply_to));
         else if (equal_ustring(name, "in_reply_to"))
            strlcpy(in_reply_to, value, sizeof(in_reply_to));
         else if (equal_ustring(name, "encoding"))
            strlcpy(encoding, value, sizeof(encoding));
         else if (!equal_ustring(name, "cmd") &&
                  !equal_ustring(name, "full_name") &&
                  !equal_ustring(name, "user_email") &&
                  !equal_ustring(name, "unm") &&
                  !equal_ustring(name, "upwd") &&
                  !equal_ustring(name, "wpwd") && strncmp(name, "attachment", 10) != 0) {
            strlcpy(attrib_name[n_attr], name, NAME_LENGTH);
            strlcpy(attrib_value[n_attr++], value, NAME_LENGTH);
         }
      } else
         break;
   }

   if (message_id == 0 || date[0] == 0) {
      show_error(loc("Invalid mirror_id or entry_date"));
      return;
   }

   /* check if message already exists */
   for (i = 0; i < *lbs->n_el_index; i++)
      if (lbs->el_index[i].message_id == message_id) {
         bedit = TRUE;
         break;
      }

   message_id =
       el_submit(lbs, message_id, bedit, date, attrib_name, attrib_value, n_attr,
                 getparam("text"), in_reply_to, reply_to, encoding, att_file,
                 FALSE, NULL);

   if (message_id <= 0) {
      sprintf(str, loc("New entry cannot be written to directory \"%s\""), lbs->data_dir);
      strcat(str, "\n<p>");
      strcat(str, loc("Please check that it exists and elogd has write access"));
      show_error(str);
      return;
   }

   sprintf(str, "%d", message_id);
   redirect(lbs, str);
}

/*------------------------------------------------------------------*/

void copy_to(LOGBOOK * lbs, int src_id, char *dest_logbook, int move, int orig_id)
{
   int size, i, n, n_done, n_done_reply, n_reply, index, status, fh, source_id,
       message_id;
   char str[256], file_name[MAX_PATH_LENGTH], attrib[MAX_N_ATTR][NAME_LENGTH];
   char date[80], *text, msg_str[32], in_reply_to[80],
       reply_to[MAX_REPLY_TO * 10],
       attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH], encoding[80], locked_by[256],
       *buffer, list[MAX_N_ATTR][NAME_LENGTH];
   LOGBOOK *lbs_dest;

   for (i = 0; lb_list[i].name[0]; i++)
      if (equal_ustring(lb_list[i].name, dest_logbook))
         break;
   if (!lb_list[i].name[0])
      return;
   lbs_dest = &lb_list[i];

   if (src_id)
      n = 1;
   else
      n = atoi(getparam("nsel"));

   text = malloc(TEXT_SIZE);

   n_done = n_done_reply = 0;
   for (index = 0; index < n; index++) {
      if (src_id)
         source_id = src_id;
      else {
         sprintf(str, "s%d", index);
         if (!isparam(str))
            continue;

         source_id = atoi(getparam(str));
      }

      /* get message */
      size = TEXT_SIZE;
      status =
          el_retrieve(lbs, source_id, date, attr_list, attrib, lbs->n_attr,
                      text, &size, in_reply_to, reply_to, attachment, encoding,
                      locked_by);

      if (status != EL_SUCCESS) {
         sprintf(msg_str, "%d", source_id);
         sprintf(str, loc("Entry %s cannot be read from logbook \"%s\""), msg_str,
                 lbs->name);
         show_error(str);
         free(text);
         return;
      }

      if (orig_id == 0) {
         /* search message head */
         while (atoi(in_reply_to) > 0) {
            source_id = atoi(in_reply_to);
            size = TEXT_SIZE;
            status =
                el_retrieve(lbs, source_id, date, attr_list, attrib,
                            lbs->n_attr, text, &size, in_reply_to, reply_to, attachment,
                            encoding, locked_by);

            if (status != EL_SUCCESS) {
               sprintf(msg_str, "%d", source_id);
               sprintf(str, loc("Entry %s cannot be read from logbook \"%s\""), msg_str,
                       lbs->name);
               show_error(str);
               free(text);
               return;
            }
         }
      }


      /* read attachments */
      for (i = 0; i < MAX_ATTACHMENTS; i++)
         if (attachment[i][0]) {
            strlcpy(file_name, lbs->data_dir, sizeof(file_name));
            strlcat(file_name, attachment[i], sizeof(file_name));

            fh = open(file_name, O_RDONLY | O_BINARY);
            if (fh > 0) {
               lseek(fh, 0, SEEK_END);
               size = TELL(fh);
               lseek(fh, 0, SEEK_SET);

               buffer = malloc(size);

               if (buffer)
                  read(fh, buffer, size);

               close(fh);

               /* stip date/time from file name */
               strlcpy(file_name, attachment[i] + 14, NAME_LENGTH);

               el_submit_attachment(lbs_dest, file_name, buffer, size, attachment[i]);

               if (buffer)
                  free(buffer);
            } else
               /* attachment is invalid */
               attachment[i][0] = 0;
         }

      /* if called recursively (for threads), put in correct in_reply_to */
      str[0] = 0;
      if (orig_id)
         sprintf(str, "%d", orig_id);

      /* submit in destination logbook without links, submit all attributes from
         the source logbook even if the destination has a differnt number of attributes */

      message_id =
          el_submit(lbs_dest, 0, FALSE, date, attr_list, attrib, lbs->n_attr, text, str,
                    "", encoding, attachment, TRUE, NULL);

      if (message_id <= 0) {
         sprintf(str, loc("New entry cannot be written to directory \"%s\""),
                 lbs_dest->data_dir);
         strcat(str, "\n<p>");
         strcat(str, loc("Please check that it exists and elogd has write access"));
         show_error(str);
         free(text);
         return;
      }

      n_done++;

      /* submit all replies */
      n_reply = strbreak(reply_to, list, MAX_N_ATTR);
      for (i = 0; i < n_reply; i++) {
         copy_to(lbs, atoi(list[i]), dest_logbook, move, message_id);
      }

      n_done_reply += n_reply;

      /* delete original message for move */
      if (move && orig_id == 0) {
         el_delete_message(lbs, source_id, TRUE, NULL, TRUE, TRUE);

         /* check if this was the last message */
         source_id = el_search_message(lbs, EL_NEXT, source_id, FALSE);

         /* if yes, force display of new last message */
         if (source_id <= 0)
            source_id = el_search_message(lbs, EL_LAST, 0, FALSE);
      }
   }

   free(text);

   if (orig_id)
      return;

   /* display status message */
   sprintf(str, "%d", source_id);
   show_standard_header(lbs, FALSE, loc("Copy ELog entry"), str);

   rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");
   rsprintf("<tr><td colspan=2 class=\"dlgtitle\">\n");

   if (n_done == 0)
      rsprintf(loc("No entry selected"));
   else {
      if (n_done == 1)
         rsprintf(loc("One entry"));
      else
         rsprintf(loc("%d messages"), n_done);

      if (n_done_reply) {
         rsprintf(" ");

         if (n_done == 1)
            rsprintf(loc("and its replies"));
         else
            rsprintf(loc("and their replies"));
      }

      rsprintf(" ");

      if (move)
         rsprintf(loc("moved successfully from \"%s\" to \"%s\""), lbs->name,
                  lbs_dest->name);
      else
         rsprintf(loc("copied successfully from \"%s\" to \"%s\""), lbs->name,
                  lbs_dest->name);
   }

   rsprintf("</b></tr>\n");
   if (src_id)
      rsprintf
          ("<tr><td align=center class=\"dlgform\">%s <a href=\"../%s/%d\">%s</td></tr>\n",
           loc("Go to"), lbs->name, source_id, lbs->name);
   else {
      strcpy(str, getparam("lastcmd"));
      url_decode(str);

      rsprintf
          ("<tr><td align=center class=\"dlgform\">%s <a href=\"../%s/%s\">%s</td></tr>\n",
           loc("Go to"), lbs->name, str, lbs->name);
   }

   rsprintf
       ("<tr><td align=center class=\"dlgform\">%s <a href=\"../%s/\">%s</td></tr>\n",
        loc("Go to"), lbs_dest->name, lbs_dest->name);

   rsprintf("</table>\n");
   show_bottom_text(lbs);
   rsprintf("</body></html>\r\n");

   return;
}

/*------------------------------------------------------------------*/

void show_elog_message(LOGBOOK * lbs, char *dec_path, char *command)
{
   int size, i, j, n, n_log, status, fh, length, message_error, index;
   int message_id, orig_message_id, format_flags[MAX_N_ATTR];
   char str[1000], ref[256], file_name[256], attrib[MAX_N_ATTR][NAME_LENGTH];
   char date[80], text[TEXT_SIZE], menu_str[1000], cmd[256], cmd_enc[256],
       orig_tag[80], reply_tag[MAX_REPLY_TO * 10],
       attachment[MAX_ATTACHMENTS][MAX_PATH_LENGTH], encoding[80], locked_by[256],
       att[256], lattr[256];
   char menu_item[MAX_N_LIST][NAME_LENGTH], format[80], admin_user[80],
       slist[MAX_N_ATTR + 10][NAME_LENGTH], svalue[MAX_N_ATTR + 10][NAME_LENGTH], *p;
   char lbk_list[MAX_N_LIST][NAME_LENGTH], comment[256], class_name[80], class_value[80],
       fl[8][NAME_LENGTH];
   FILE *f;
   BOOL first;
   struct tm ts;

   message_id = atoi(dec_path);
   message_error = EL_SUCCESS;
   _current_message_id = message_id;

   /* check for guest access */
   if (!getcfg(lbs->name, "Guest Menu commands", menu_str) || *getparam("unm") != 0)
      getcfg(lbs->name, "Menu commands", menu_str);

   /* default menu commands */
   if (menu_str[0] == 0) {
      strcpy(menu_str, "Back, New, Edit, Delete, Reply, Find, ");

      if (getcfg(lbs->name, "Password file", str)) {
         strcat(menu_str, "Config, Logout, ");
      } else {
         strcat(menu_str, "Config, ");
      }

      strcat(menu_str, "Help");
   } else {
      /* check for admin command */
      n = strbreak(menu_str, menu_item, MAX_N_LIST);
      menu_str[0] = 0;
      admin_user[0] = 0;
      getcfg(lbs->name, "Admin user", admin_user);
      for (i = 0; i < n; i++) {
         if (strcmp(menu_item[i], "Admin") == 0) {
            if (strstr(admin_user, getparam("unm")) == NULL)
               continue;
         }
         strcat(menu_str, menu_item[i]);
         if (i < n - 1)
            strcat(menu_str, ", ");
      }
   }

   /*---- check next/previous message -------------------------------*/

   if (equal_ustring(command, loc("Next"))
       || equal_ustring(command, loc("Previous"))
       || equal_ustring(command, loc("Last"))
       || equal_ustring(command, loc("First"))) {
      orig_message_id = message_id;

      if (equal_ustring(command, loc("Last")))
         message_id = el_search_message(lbs, EL_LAST, 0, FALSE);

      if (equal_ustring(command, loc("First")))
         message_id = el_search_message(lbs, EL_FIRST, 0, FALSE);

      if (!message_id) {
         redirect(lbs, "");
         return;
      }

      first = TRUE;
      do {
         if (equal_ustring(command, loc("Next")))
            message_id = el_search_message(lbs, EL_NEXT, message_id, FALSE);

         if (equal_ustring(command, loc("Previous")))
            message_id = el_search_message(lbs, EL_PREV, message_id, FALSE);

         if (!first) {
            if (equal_ustring(command, loc("First")))
               message_id = el_search_message(lbs, EL_NEXT, message_id, FALSE);


            if (equal_ustring(command, loc("Last")))
               message_id = el_search_message(lbs, EL_PREV, message_id, FALSE);
         } else
            first = FALSE;

         if (message_id == 0) {
            if (equal_ustring(command, loc("Next")))
               message_error = EL_LAST_MSG;
            else
               message_error = EL_FIRST_MSG;

            message_id = orig_message_id;
            break;
         }

         size = sizeof(text);
         el_retrieve(lbs, message_id, date, attr_list, attrib, lbs->n_attr,
                     text, &size, orig_tag, reply_tag, attachment, encoding, locked_by);

         /* check for locked attributes */
         for (i = 0; i < lbs->n_attr; i++) {
            sprintf(lattr, "l%s", attr_list[i]);
            if (*getparam(lattr) == '1'
                && !equal_ustring(getparam(attr_list[i]), attrib[i]))
               break;
         }
         if (i < lbs->n_attr)
            continue;

         /* check for attribute filter if not browsing */
         if (!*getparam("browsing")) {
            for (i = 0; i < lbs->n_attr; i++) {
               if (*getparam(attr_list[i])
                   && !equal_ustring(getparam(attr_list[i]), attrib[i]))
                  break;
            }
            if (i < lbs->n_attr)
               continue;
         }

         sprintf(str, "%d", message_id);

         for (i = 0; i < lbs->n_attr; i++) {
            sprintf(lattr, "l%s", attr_list[i]);
            if (*getparam(lattr) == '1') {
               if (strchr(str, '?') == NULL)
                  sprintf(str + strlen(str), "?%s=1", lattr);
               else
                  sprintf(str + strlen(str), "&%s=1", lattr);
            }
         }

         redirect(lbs, str);
         return;

      } while (TRUE);
   }

   /*---- check for valid URL ---------------------------------------*/

   if (dec_path[0] && atoi(dec_path) == 0) {
      sprintf(str, "Invalid URL: <b>%s</b>", dec_path);
      show_error(str);
      return;
   }

   /*---- get current message ---------------------------------------*/

   if (message_id == 0)
      message_id = el_search_message(lbs, EL_LAST, 0, FALSE);

   if (message_id) {
      size = sizeof(text);
      status =
          el_retrieve(lbs, message_id, date, attr_list, attrib,
                      lbs->n_attr, text, &size, orig_tag, reply_tag, attachment, encoding,
                      locked_by);

      if (status != EL_SUCCESS)
         message_error = status;
      else {
         if (_logging_level > 2)
            logf(lbs, "READ entry #%d", message_id);
      }
   } else
      message_error = EL_EMPTY;

   /*---- header ----*/

   /* header */
   if (status == EL_SUCCESS && message_error != EL_EMPTY) {
      str[0] = 0;

      if (getcfg(lbs->name, "Page Title", str)) {
         i = build_subst_list(lbs, slist, svalue, attrib);
         strsubst(str, slist, svalue, i);
      } else
         strcpy(str, "ELOG");

      sprintf(ref, "%d", message_id);
      if (str[0])
         show_standard_header(lbs, TRUE, str, ref);
      else
         show_standard_header(lbs, TRUE, lbs->name, ref);
   } else
      show_standard_header(lbs, TRUE, "", "");

   /*---- title ----*/

   show_standard_title(lbs->name, "", 0);

   /*---- menu buttons ----*/

   rsprintf("<tr><td class=\"menuframe\">\n");
   rsprintf("<table width=\"100%%\" border=0 cellpadding=0 cellspacing=0>\n");
   rsprintf("<tr><td class=\"menu1\">\n");

   n = strbreak(menu_str, menu_item, MAX_N_LIST);

   for (i = 0; i < n; i++) {
      /* display menu item */
      strcpy(cmd, menu_item[i]);

      /* only display allowed commands */
      if (!is_user_allowed(lbs, cmd))
         continue;

      if (equal_ustring(cmd, "Copy to") || equal_ustring(cmd, "Move to")) {
         if (getcfg(lbs->name, cmd, str)) {
            n_log = strbreak(str, lbk_list, MAX_N_LIST);

            for (j = 0; j < n_log; j++) {
               strcpy(ref, lbk_list[j]);
               url_encode(ref, sizeof(ref));

               strcpy(cmd_enc, loc(cmd));
               url_encode(cmd_enc, sizeof(cmd_enc));

               if (equal_ustring(cmd, loc("Copy to")))
                  rsprintf
                      ("&nbsp;<a href=\"../%s/%d?cmd=%s&destc=%s\">%s \"%s\"</a>&nbsp|\n",
                       lbs->name_enc, message_id, cmd_enc, ref, loc(cmd), lbk_list[j]);
               else
                  rsprintf
                      ("&nbsp;<a href=\"../%s/%d?cmd=%s&destm=%s\">%s \"%s\"</a>&nbsp|\n",
                       lbs->name_enc, message_id, cmd_enc, ref, loc(cmd), lbk_list[j]);
            }
         } else {
            /* put one link for each logbook except current one */
            for (j = 0;; j++) {
               if (!enumgrp(j, str))
                  break;

               if (!is_logbook(str))
                  continue;

               if (equal_ustring(str, lbs->name))
                  continue;

               strlcpy(ref, str, sizeof(ref));
               url_encode(ref, sizeof(ref));

               strcpy(cmd_enc, loc(cmd));
               url_encode(cmd_enc, sizeof(cmd_enc));

               if (equal_ustring(cmd, "Copy to"))
                  rsprintf
                      ("&nbsp;<a href=\"../%s/%d?cmd=%s&amp;destc=%s\">%s \"%s\"</a>&nbsp|\n",
                       lbs->name_enc, message_id, cmd_enc, ref, loc(cmd), str);
               else
                  rsprintf
                      ("&nbsp;<a href=\"../%s/%d?cmd=%s&amp;destm=%s\">%s \"%s\"</a>&nbsp|\n",
                       lbs->name_enc, message_id, cmd_enc, ref, loc(cmd), str);
            }
         }
      } else {
         strcpy(str, loc(menu_item[i]));
         url_encode(str, sizeof(str));

         if (i < n - 1)
            rsprintf("&nbsp;<a href=\"%d?cmd=%s\">%s</a>&nbsp;|\n", message_id, str,
                     loc(menu_item[i]));
         else
            rsprintf("&nbsp;<a href=\"%d?cmd=%s\">%s</a>&nbsp;\n", message_id, str,
                     loc(menu_item[i]));
      }
   }

   rsprintf("</td>\n\n");

   /*---- next/previous buttons ----*/

   if (!getcfg(lbs->name, "Enable browsing", str) || atoi(str) == 1) {
      rsprintf("<td width=\"10%%\" nowrap align=right>\n");

      rsprintf("<input type=image name=cmd_first alt=\"%s\" src=\"first.gif\">\n",
               loc("First entry"));
      rsprintf("<input type=image name=cmd_previous alt=\"%s\" src=\"previous.gif\">\n",
               loc("Previous entry"));
      rsprintf("<input type=image name=cmd_next alt=\"%s\" src=\"next.gif\">\n",
               loc("Next entry"));
      rsprintf("<input type=image name=cmd_last alt=\"%s\" src=\"last.gif\">\n",
               loc("Last entry"));

      rsprintf("</td></tr>\n");
   }

   rsprintf("</table></td></tr>\n\n");

   /*---- menu text ----*/

   if (getcfg(lbs->name, "menu text", str)) {
      FILE *f;
      char file_name[256], *buf;

      rsprintf("<tr><td class=\"menuframe\"><span class=\"menu1\">\n");

      /* check if file starts with an absolute directory */
      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strcpy(file_name, str);
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }

      f = fopen(file_name, "rb");
      if (f != NULL) {
         fseek(f, 0, SEEK_END);
         size = TELL(fileno(f));
         fseek(f, 0, SEEK_SET);

         buf = malloc(size + 1);
         fread(buf, 1, size, f);
         buf[size] = 0;
         fclose(f);


         rsputs(buf);

      } else
         rsprintf("<center><b>Error: file <i>\"%s\"</i> not found</b></center>",
                  file_name);

      rsprintf("</span></td></tr>");
   }

   /*---- message ----*/

   if (message_error == EL_EMPTY)
      rsprintf("<tr><td class=\"errormsg\" colspan=2>%s</td></tr>\n",
               loc("Logbook is empty"));
   else if (message_error == EL_NO_MSG)
      rsprintf("<tr><td class=\"errormsg\" colspan=2>%s</td></tr>\n",
               loc("This entry has been deleted"));
   else {
      /* overall message table */
      rsprintf
          ("<tr><td><table class=\"listframe\" width=\"100%%\" cellspacing=0 cellpadding=0>\n");

      /* check for locked attributes */
      for (i = 0; i < lbs->n_attr; i++) {
         sprintf(lattr, "l%s", attr_list[i]);
         if (*getparam(lattr) == '1')
            break;
      }
      if (i < lbs->n_attr)
         sprintf(str, " %s <i>\"%s = %s\"</i>", loc("with"), attr_list[i],
                 getparam(attr_list[i]));
      else
         str[0] = 0;

      if (message_error == EL_LAST_MSG)
         rsprintf("<tr><td class=\"notifymsg\" colspan=2>%s %s</td></tr>\n",
                  loc("This is the last entry"), str);

      if (message_error == EL_FIRST_MSG)
         rsprintf("<tr><td class=\"notifymsg\" colspan=2>%s %s</td></tr>\n",
                  loc("This is the first entry"), str);

      /* check for mail submissions */
      if (*getparam("suppress")) {
         rsprintf("<tr><td class=\"notifymsg\" colspan=2>%s</td></tr>\n",
                  loc("Email notification suppressed"));
      } else if (isparam("error")) {
         rsprintf("<tr><td class=\"errormsg\" colspan=2>%s</td></tr>\n",
                  getparam("error"));
      } else {
         for (i = 0;; i++) {
            sprintf(str, "mail%d", i);
            if (*getparam(str)) {
               if (i == 0)
                  rsprintf("<tr><td class=\"notifymsg\" colspan=2>");
               rsprintf("%s <b>%s</b><br>\n", loc("Email sent to"), getparam(str));
            } else
               break;
         }
         if (i > 0)
            rsprintf("</tr>\n");
      }

      /*---- display message ID ----*/

      if (locked_by && locked_by[0]) {
         sprintf(str, "%s %s", loc("Entry is currently edited by"), locked_by);
         rsprintf("<tr><td nowrap colspan=2 class=\"errormsg\"><img src=\"stop.gif\">\n");
         rsprintf("%s</td></tr>\n", str);
      }

      rsprintf("<tr><td class=\"attribhead\">\n");

      for (i = 0; i < lbs->n_attr; i++)
         rsprintf("<input type=hidden name=\"%s\" value=\"%s\">\n", attr_list[i],
                  attrib[i]);

      /* browsing flag to distinguish "/../<attr>=<value>" from browsing */
      rsprintf("<input type=hidden name=browsing value=1>\n");

      rsprintf("%s:&nbsp;<b>%d</b>\n", loc("Message ID"), message_id);

      /*---- display date ----*/

      if (!getcfg(lbs->name, "Date format", format))
         strcpy(format, DEFAULT_DATE_FORMAT);

      memset(&ts, 0, sizeof(ts));

      for (i = 0; i < 12; i++)
         if (strncmp(date + 4, mname[i], 3) == 0)
            break;
      ts.tm_mon = i;

      ts.tm_mday = atoi(date + 8);
      ts.tm_hour = atoi(date + 11);
      ts.tm_min = atoi(date + 14);
      ts.tm_sec = atoi(date + 17);
      ts.tm_year = atoi(date + 20) - 1900;
      ts.tm_isdst = -1;         /* let mktime compute DST */

      mktime(&ts);
      strftime(str, sizeof(str), format, &ts);

      rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;%s:&nbsp;<b>%s</b>\n", loc("Entry date"), str);

      /*---- link to original message or reply ----*/

      if (message_error != EL_FILE_ERROR && (reply_tag[0] || orig_tag[0])) {

         if (orig_tag[0]) {
            sprintf(ref, "%s", orig_tag);
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;%s:&nbsp;", loc("In reply to"));
            rsprintf("<b><a href=\"%s\">%s</a></b>\n", ref, orig_tag);
         }
         if (reply_tag[0]) {
            rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;%s:&nbsp;<b>", loc("Reply to this"));

            p = strtok(reply_tag, ",");
            do {
               rsprintf("<a href=\"%s\">%s</a>\n", p, p);

               p = strtok(NULL, ",");

               if (p)
                  rsprintf("&nbsp; \n");

            } while (p);

            rsprintf("</b>\n");
         }
      }

      rsprintf("</td></tr>\n");

      /*---- display attributes ----*/

      /* retrieve attribute flags */
      for (i = 0; i < lbs->n_attr; i++) {
         format_flags[i] = 0;
         sprintf(str, "Format %s", attr_list[i]);
         if (getcfg(lbs->name, str, format)) {
            n = strbreak(format, fl, 8);
            if (n > 0)
               format_flags[i] = atoi(fl[0]);
         }
      }

      for (i = 0; i < lbs->n_attr; i++) {
         strcpy(class_name, "attribname");
         strcpy(class_value, "attribvalue");

         sprintf(str, "Format %s", attr_list[i]);
         if (getcfg(lbs->name, str, format)) {
            n = strbreak(format, fl, 8);
            if (n > 1)
               strlcpy(class_name, fl[1], sizeof(class_name));
            if (n > 2)
               strlcpy(class_value, fl[2], sizeof(class_value));
         }

         if ((format_flags[i] & AFF_SAME_LINE) == 0)
            rsprintf("<tr><td><table width=\"100%%\" cellpadding=0 cellspacing=0><tr>");

         sprintf(lattr, "l%s", attr_list[i]);
         rsprintf("<td nowrap class=\"%s\">", class_name);

         if (getcfg(lbs->name, "Filtered browsing", str) && atoi(str) == 1) {
            if (*getparam(lattr) == '1')
               rsprintf("<input type=\"checkbox\" checked name=\"%s\" value=\"1\">&nbsp;",
                        lattr);
            else
               rsprintf
                   ("<input alt=\"text\" type=\"checkbox\" name=\"%s\" value=\"1\">&nbsp;",
                    lattr);
         }

         /* display checkbox for boolean attributes */
         if (equal_ustring(attr_options[i][0], "boolean")) {
            if (atoi(attrib[i]) == 1)
               rsprintf
                   ("%s:</td><td class=\"%s\"><input type=checkbox checked disabled></td>\n",
                    attr_list[i], class_value);
            else
               rsprintf("%s:</td><td class=\"%s\"><input type=checkbox disabled></td>\n",
                        attr_list[i], class_value);
         }
         /* display image for icon */
         else if (attr_flags[i] & AF_ICON) {
            rsprintf("%s:</td><td class=\"%s\">\n", attr_list[i], class_value);
            if (attrib[i][0]) {
               sprintf(str, "Icon comment %s", attrib[i]);
               getcfg(lbs->name, str, comment);

               if (comment[0])
                  rsprintf("<img src=\"icons/%s\" alt=\"%s\">", attrib[i], comment);
               else
                  rsprintf("<img src=\"icons/%s\" alt=\"%s\">", attrib[i], attrib[i]);
            }
            rsprintf("&nbsp</td>\n");
         } else if ((attr_flags[i] & AF_MULTI)
                    && (format_flags[i] & AFF_MULTI_LINE)) {
            rsprintf("%s:</td><td class=\"%s\">\n", attr_list[i], class_value);

            /* separate options into individual lines */
            strlcpy(str, attrib[i], sizeof(str));
            p = strtok(str, "|");
            while (p) {
               while (*p == ' ')
                  p++;

               rsputs2(p);

               p = strtok(NULL, "|");

               if (p)
                  rsprintf("<br>");
            }

            rsprintf("</td>\n");
         } else {
            rsprintf("%s:</td><td class=\"%s\">\n", attr_list[i], class_value);
            rsputs2(attrib[i]);
            rsprintf("&nbsp</td>\n");
         }

         if (i == lbs->n_attr - 1 || (format_flags[i + 1] & AFF_SAME_LINE) == 0)
            rsprintf("</tr></table></td></tr>\n");
      }

      rsputs("</table><!-- listframe -->\n");

      rsputs("</td></tr>\n");

      /*---- message text ----*/

      if (!getcfg(lbs->name, "Show text", str) || atoi(str) == 1) {
         rsprintf("<tr><td class=\"messageframe\">\n");

         if (equal_ustring(encoding, "plain")) {
            rsputs("<pre class=\"messagepre\">");
            rsputs2(text);
            rsputs("</pre>");
         } else
            rsputs(text);

         rsputs("</td></tr>\n");
      }

      for (index = 0; index < MAX_ATTACHMENTS; index++) {
         if (attachment[index][0] && strlen(attachment[index]) > 14) {
            for (i = 0; i < (int) strlen(attachment[index]); i++)
               att[i] = toupper(attachment[index][i]);
            att[i] = 0;

            /* determine size of attachment */
            strlcpy(file_name, lbs->data_dir, sizeof(file_name));
            strlcat(file_name, attachment[index], sizeof(file_name));

            length = 0;
            fh = open(file_name, O_RDONLY | O_BINARY);
            if (fh > 0) {
               lseek(fh, 0, SEEK_END);
               length = TELL(fh);
               close(fh);
            }

            strcpy(str, attachment[index]);
            str[13] = 0;
            sprintf(ref, "%s/%s", str, attachment[index] + 14);
            url_encode(ref, sizeof(ref));       /* for file names with special characters like "+" */

            /* overall table */
            rsprintf
                ("<tr><td><table class=\"listframe\" width=\"100%%\" cellspacing=0>\n");

            rsprintf("<tr><td nowrap width=\"10%%\" class=\"attribname\">%s %d:</td>\n",
                     loc("Attachment"), index + 1);

            rsprintf("<td class=\"attribvalue\"><a href=\"%s\">%s</a>\n", ref,
                     attachment[index] + 14);

            rsprintf("&nbsp;<span class=\"bytes\">");

            if (length < 1024)
               rsprintf("%d Bytes", length);
            else if (length < 1024 * 1024)
               rsprintf("%d kB", length / 1024);
            else
               rsprintf("%1.3lf MB", length / 1024.0 / 1024.0);

            rsprintf("</span></td></tr></table></td></tr>\n");

            if (!getcfg(lbs->name, "Show attachments", str) || atoi(str) == 1) {
               if (strstr(att, ".GIF") || strstr(att, ".JPG") || strstr(att, ".JPEG")
                   || strstr(att, ".PNG")) {
                  rsprintf("<tr><td class=\"messageframe\">\n");
                  rsprintf("<a name=\"att%d\">\n", index + 1);
                  rsprintf("<img src=\"%s\"></td></tr>", ref);
                  rsprintf("</td></tr>\n\n");
               } else {
                  if (strstr(att, ".TXT") || strstr(att, ".ASC")
                      || strchr(att, '.') == NULL) {
                     /* display attachment */
                     rsprintf("<tr><td class=\"messageframe\">\n");

                     /* anchor for references */
                     rsprintf("<a name=\"att%d\">\n", index + 1);

                     if (!strstr(att, ".HTML"))
                        rsprintf("<pre class=\"messagepre\">");

                     strlcpy(file_name, lbs->data_dir, sizeof(file_name));
                     strlcat(file_name, attachment[index], sizeof(file_name));

                     f = fopen(file_name, "rt");
                     if (f != NULL) {
                        while (!feof(f)) {
                           str[0] = 0;
                           fgets(str, sizeof(str), f);

                           if (!strstr(att, ".HTML"))
                              rsputs2(str);
                           else
                              rsputs(str);
                        }
                        fclose(f);
                     }

                     if (!strstr(att, ".HTML"))
                        rsprintf("</pre>");
                     rsprintf("\n");
                     rsprintf("</td></tr>\n");
                  }
               }
            }
         }
      }
   }

   /* overall table (class "frame" from show_standard_header) */
   rsprintf("\r\n</table><!-- show_standard_title -->\r\n");

   show_bottom_text(lbs);
   rsprintf("</form></body></html>\r\n");
}

/*------------------------------------------------------------------*/

BOOL check_password(LOGBOOK * lbs, char *name, char *password, char *redir)
{
   char str[256];

   /* get password from configuration file */
   if (getcfg(lbs->name, name, str)) {
      if (strcmp(password, str) == 0)
         return TRUE;

      if (!isparam("wpwd") && password[0]) {
         strlcpy(str, redir, sizeof(str));
         if (strchr(str, '?'))
            strlcat(str, "&wpwd=1", sizeof(str));
         else
            strlcat(str, "?wpwd=1", sizeof(str));
         redirect(lbs, str);
         return FALSE;
      }

      /* show web password page */
      show_standard_header(lbs, FALSE, loc("ELOG password"), NULL);

      rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");

      if (isparam("wpwd"))
         rsprintf("<tr><td class=\"dlgerror\">%s!</td></tr>\n", loc("Wrong password"));

      rsprintf("<tr><td class=\"dlgtitle\">\n");

      /* define hidden fields for current destination */
      if (redir[0])
         rsprintf("<input type=hidden name=redir value=\"%s\">\n", redir);

      if (strcmp(name, "Write password") == 0) {
         rsprintf("%s</td></tr>\n", loc("Please enter password to obtain write access"));
         rsprintf
             ("<tr><td align=center class=\"dlgform\"><input type=password name=wpassword></td></tr>\n");
      } else {
         rsprintf("%s</td></tr>\n",
                  loc("Please enter password to obtain administration access"));
         rsprintf
             ("<tr><td align=center class=\"dlgform\"><input type=password name=apassword></td></tr>\n");
      }

      rsprintf
          ("<tr><td align=center class=\"dlgform\"><input type=submit value=\"%s\"></td></tr>",
           loc("Submit"));

      rsprintf("</table>\n");
      show_bottom_text(lbs);
      rsprintf("</body></html>\r\n");

      return FALSE;
   } else
      return TRUE;
}

/*------------------------------------------------------------------*/

int get_user_line(char *logbook_name, char *user, char *password, char *full_name,
                  char *email, char *email_notify)
{
   char str[256], line[256], file_name[256], *p;
   FILE *f;
   int i, fd;

   if (password)
      password[0] = 0;
   if (full_name)
      full_name[0] = 0;
   if (email)
      email[0] = 0;
   if (email_notify)
      email_notify[0] = 0;

   getcfg(logbook_name, "Password file", str);

   if (!str[0])
      return 1;

   if (str[0] == DIR_SEPARATOR || str[1] == ':')
      strlcpy(file_name, str, sizeof(file_name));
   else {
      strlcpy(file_name, resource_dir, sizeof(file_name));
      strlcat(file_name, str, sizeof(file_name));
   }

   f = fopen(file_name, "r");

   /* if password file doen't exist, try to create it */
   if (f == NULL) {
      fd = open(file_name, O_CREAT | O_RDWR, 0600);
      if (fd < 0)
         return 3;
      close(fd);
      f = fopen(file_name, "r");
   }

   if (f != NULL) {
      if (!user[0]) {
         fclose(f);
         return 1;
      }

      while (!feof(f)) {
         line[0] = 0;
         fgets(line, sizeof(line), f);

         if (line[0] == ';' || line[0] == '#' || line[0] == 0)
            continue;

         strcpy(str, line);
         if (strchr(str, ':'))
            *strchr(str, ':') = 0;
         if (strcmp(str, user) == 0)
            break;
      }
      fclose(f);

      if (strcmp(str, user) != 0)
         return 2;

      /* if user found, retrieve other info */
      p = line;

      for (i = 0; i < 4; i++) {
         if (strchr(p, ':') == NULL)
            break;
         p = strchr(p, ':') + 1;

         while (*p && *p == ' ')
            p++;
         strlcpy(str, p, sizeof(str));
         if (strchr(str, ':'))
            *strchr(str, ':') = 0;

         while (str[strlen(str) - 1] == ' ' || str[strlen(str) - 1] == '\r'
                || str[strlen(str) - 1] == '\n')
            str[strlen(str) - 1] = 0;

         if (i == 0 && password)
            strcpy(password, str);
         else if (i == 1 && full_name)
            strcpy(full_name, str);
         else if (i == 2 && email)
            strcpy(email, str);
         else if (i == 3 && email_notify)
            strcpy(email_notify, str);
      }

      return 1;
   } else {
      if (user[0])
         return 3;
      else
         return 1;
   }
}

/*------------------------------------------------------------------*/

BOOL enum_user_line(LOGBOOK * lbs, int n, char *user)
{
   char str[256], line[256], file_name[256];
   FILE *f;
   int i;

   getcfg(lbs->name, "Password file", str);

   if (!str[0])
      return FALSE;

   if (str[0] == DIR_SEPARATOR || str[1] == ':')
      strcpy(file_name, str);
   else {
      strlcpy(file_name, resource_dir, sizeof(file_name));
      strlcat(file_name, str, sizeof(file_name));
   }

   f = fopen(file_name, "r");
   i = 0;
   if (f != NULL) {
      while (!feof(f)) {
         line[0] = 0;
         fgets(line, sizeof(line), f);

         if (line[0] == ';' || line[0] == '#' || line[0] == 0)
            continue;

         if (strchr(line, ':') == NULL)
            continue;

         strcpy(str, line);
         if (strchr(str, ':'))
            *strchr(str, ':') = 0;

         if (i == n) {
            strcpy(user, str);
            fclose(f);
            return TRUE;
         }

         i++;
      }
      fclose(f);
   }

   return FALSE;
}

/*------------------------------------------------------------------*/

BOOL check_login_user(LOGBOOK * lbs, char *user)
{
   int i, n;
   char str[1000];
   char list[MAX_N_LIST][NAME_LENGTH];

   if (getcfg(lbs->name, "Login user", str) && user[0]) {
      n = strbreak(str, list, MAX_N_LIST);
      for (i = 0; i < n; i++)
         if (strcmp(user, list[i]) == 0)
            break;

      if (i == n)
         return FALSE;
   }
   return TRUE;
}

/*------------------------------------------------------------------*/

BOOL check_user_password(LOGBOOK * lbs, char *user, char *password, char *redir)
{
   char status, str[1000], upwd[256], full_name[256], email[256];

   if (lbs == NULL)
      status = get_user_line("global", user, upwd, full_name, email, NULL);
   else
      status = get_user_line(lbs->name, user, upwd, full_name, email, NULL);

   /* check for logout */
   if (isparam("LO")) {
      /* remove cookies */
      set_login_cookies(lbs, "", "");
      return FALSE;
   }

   /* check for "forgot password" */
   if (isparam("cmd") && strcmp(getparam("cmd"), loc("Forgot")) == 0) {
      show_forgot_pwd_page(lbs);
      return FALSE;
   }

   /* display error message for invalid user */
   if (isparam("iusr")) {
      /* header */
      show_html_header(NULL, FALSE, "ELOG error", TRUE);

      rsprintf("<body><center>\n");
      rsprintf("<table class=\"dlgframe\" width=\"50%%\" cellpadding=1 cellspacing=0>");
      sprintf(str, loc("User <i>\"%s\"</i> has no access to logbook <i>\"%s\"</i>"),
              getparam("iusr"), lbs->name);
      rsprintf("<tr><td class=\"errormsg\">%s</td></tr>\n", str);

      rsprintf("<tr><td class=\"errormsg\">");
      rsprintf("<a href=\"?LO=1\">%s</a></td></tr>", loc("Login as different user"));

      rsprintf("<tr><td class=\"errormsg\">");
      rsprintf("<a href=\"../\">%s</a></td></tr>", loc("Goto logbook selection page"));

      rsprintf("</table>\n");
      rsprintf("</center></body></html>\n");

      return FALSE;
   }

   if (!check_login_user(lbs, user)) {
      sprintf(str, "?iusr=%s", user);

      redirect(lbs, str);
      return FALSE;
   }

   if (status == 1) {
      if (user[0] && strcmp(password, upwd) == 0) {
         setparam("full_name", full_name);
         setparam("user_email", email);
         return TRUE;
      }

      if (!isparam("wpwd") && password[0]) {
         redirect(lbs, "?wpwd=1");
         return FALSE;
      }

      /* show login password page */
      sprintf(str, "ELOG %s", loc("Login"));
      show_html_header(lbs, TRUE, str, TRUE);

      /* set focus on name field */
      rsprintf("<body OnLoad=\"document.form1.uname.focus();\">\n");

      rsprintf("<form name=form1 method=\"GET\" action=\"\">\n\n");

      /* define hidden fields for current destination */
      rsprintf("<input type=hidden name=redir value=\"%s\">\n", redir);

      rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");

      if (isparam("wpwd"))
         rsprintf("<tr><td colspan=2 class=\"dlgerror\">%s!</td></tr>\n",
                  loc("Wrong password"));

      if (isparam("wusr")) {
         sprintf(str, loc("Invalid user name <i>\"%s\"</i>"), getparam("wusr"));
         rsprintf("<tr><td colspan=2 class=\"dlgerror\">%s!</td></tr>\n", str);
      }

      rsprintf("<tr><td colspan=2 class=\"dlgtitle\">%s</td></tr>\n",
               loc("Please login"));

      rsprintf("<tr><td align=right class=\"dlgform\">%s:</td>\n", loc("Username"));
      rsprintf
          ("<td align=left class=\"dlgform\"><input type=text name=uname value=\"%s\"></td></tr>\n",
           getparam("unm"));

      rsprintf("<tr><td align=right class=\"dlgform\">%s:</td>\n", loc("Password"));
      rsprintf
          ("<td align=left class=\"dlgform\"><input type=password name=upassword></td></tr>\n");

      if (!getcfg(lbs->name, "Login expiration", str) || atoi(str) > 0) {
         rsprintf
             ("<td align=center colspan=2 class=\"dlgform\"><input type=checkbox checked name=remember value=1>\n");
         rsprintf("%s</td></tr>\n", loc("Remember me on this computer"));
      }

      rsprintf
          ("<tr><td align=center colspan=2 class=\"dlgform\"><a href=\"?cmd=%s\">%s</a>",
           loc("Forgot"), loc("Forgot password?"));

      if (getcfg(lbs->name, "Self register", str) && atoi(str) > 0) {
         strcpy(str, loc("New user"));
         url_encode(str, sizeof(str));
         rsprintf("&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<a href=\"?cmd=%s\">%s</td></tr>",
                  str, loc("Register as new user"));
      }

      rsprintf
          ("<tr><td align=center colspan=2 class=\"dlgform\"><input type=submit value=\"%s\"></td></tr>",
           loc("Submit"));

      rsprintf("</table>\n");

      rsprintf
          ("<center><a class=\"bottomlink\" href=\"http://midas.psi.ch/elog/\">ELOG V%s</a></center>",
           VERSION);

      rsprintf("</body></html>\r\n");

      return FALSE;
   } else {
      if (status == 2) {

         sprintf(str, "?wusr=%s", user);
         setparam("redir", str);

         /* remove remaining cookies */
         set_login_cookies(lbs, "", "");
      } else {
         getcfg(lbs->name, "Password file", full_name);
         sprintf(str, loc("Cannot open file <b>%s</b>"), full_name);

         show_error(str);
      }
      return FALSE;
   }
}

/*------------------------------------------------------------------*/

int node_contains(LBLIST pn, char *logbook)
{
   int i;

   for (i = 0; i < pn->n_members; i++) {

      /* check if logbook in this group */
      if (equal_ustring(pn->member[i]->name, logbook))
         return 1;

      /* check if loogbook is in subgroups */
      if (pn->member[i]->n_members > 0 && node_contains(pn->member[i], logbook))
         return 1;
   }

   return 0;
}

/*------------------------------------------------------------------*/

void show_logbook_node(LBLIST plb, LBLIST pparent, int level, int btop)
{
   int i, index, j, expand;
   char str[10000], format[256], date[256], ref[256], slist[MAX_N_ATTR + 10][NAME_LENGTH],
       svalue[MAX_N_ATTR + 10][NAME_LENGTH];
   struct tm ts;

   if (plb->n_members > 0) {

      expand = 0;
      if (isparam("gexp")) {
         if (equal_ustring(plb->name, getparam("gexp")) ||
             node_contains(plb, getparam("gexp")) ||
             equal_ustring(getparam("gexp"), "all"))
            expand = 1;
      }

      /* do not display top groups */
      if (!plb->is_top) {

         rsprintf("<tr>");
         for (i = 0; i < level; i++)
            rsprintf("<td class=\"selspace\">&nbsp;</td>\n");
         rsprintf("<td colspan=%d class=\"selgroup\">", 13 - level);
         for (i = 0; i < level; i++)
            rsprintf("&nbsp;&nbsp;");
         if (expand) {
            if (pparent == NULL)
               sprintf(ref, ".");
            else
               sprintf(ref, "?gexp=%s", pparent->name);

            rsprintf("<a href=\"%s\">- %s</a> ", ref, plb->name);
         } else {
            sprintf(ref, "?gexp=%s", plb->name);
            rsprintf("<a href=\"%s\">+ %s</a> ", ref, plb->name);
         }

         rsprintf("</td></tr>\n");
      }

      if (plb->is_top || expand)
         for (i = 0; i < plb->n_members; i++)
            show_logbook_node(plb->member[i], plb->is_top ? NULL : plb, level + 1, btop);
   } else {

      if (!getcfg(plb->name, "Hidden", str) || atoi(str) == 0) {

         /* search logbook in list */
         for (index = 0; lb_list[index].name[0]; index++)
            if (equal_ustring(plb->name, lb_list[index].name))
               break;
         if (!lb_list[index].name[0])
            return;
         rsprintf("<tr>");
         for (j = 0; j < level; j++)
            rsprintf("<td class=\"selspace\">&nbsp;</td>\n");
         rsprintf("<td colspan=%d class=\"sellogbook\">", 10 - level);
         /* add one ".." if we are under top group */
         if (btop)
            rsprintf("<a href=\"../%s/\">%s</a>", lb_list[index].name_enc,
                     lb_list[index].name);
         else
            rsprintf("<a href=\"%s/\">%s</a>", lb_list[index].name_enc,
                     lb_list[index].name);
         if (getcfg(lb_list[index].name, "Read password", str)
             || (getcfg(lb_list[index].name, "Password file", str)
                 && !getcfg(lb_list[index].name, "Guest menu commands", str)))
            rsprintf("&nbsp;&nbsp;<img src=\"lock.gif\">");
         rsprintf("<br>\n");
         str[0] = 0;
         getcfg(lb_list[index].name, "Comment", str);
         rsprintf("<span class=\"selcomment\">%s</span></td>\n", str);
         rsprintf("<td nowrap class=\"selentries\">");
         rsprintf("%d", *lb_list[index].n_el_index);
         rsprintf("</td>\n");
         rsprintf("<td nowrap class=\"selentries\">");
         if (*lb_list[index].n_el_index == 0)
            rsprintf("-");
         else {
            char attrib[MAX_N_ATTR][NAME_LENGTH];

            lb_list[index].n_attr = scan_attributes(lb_list[index].name, NULL);
            j = el_search_message(&lb_list[index], EL_LAST, 0, FALSE);
            el_retrieve(&lb_list[index],
                        j, date, attr_list, attrib, lb_list[index].n_attr, NULL, 0, NULL,
                        NULL, NULL, NULL, NULL);
            if (!getcfg(lb_list[index].name, "Last submission", str)) {
               sprintf(str, "$entry date");
               for (i = 0; i < lb_list[index].n_attr; i++)
                  if (equal_ustring(attr_list[i], "Author"))
                     break;
               if (i < lb_list[index].n_attr)
                  sprintf(str + strlen(str), " %s $author", loc("by"));
            }
            j = build_subst_list(&lb_list[index], slist, svalue, attrib);
            strcpy(slist[j], "entry date");
            if (!getcfg(lb_list[index].name, "Date format", format))
               strcpy(format, DEFAULT_DATE_FORMAT);

            memset(&ts, 0, sizeof(ts));
            for (i = 0; i < 12; i++)
               if (strncmp(date + 4, mname[i], 3) == 0)
                  break;
            ts.tm_mon = i;
            ts.tm_mday = atoi(date + 8);
            ts.tm_hour = atoi(date + 11);
            ts.tm_min = atoi(date + 14);
            ts.tm_sec = atoi(date + 17);
            ts.tm_year = atoi(date + 20) - 1900;
            ts.tm_isdst = -1;   /* let mktime compute DST */
            mktime(&ts);
            strftime(svalue[j++], sizeof(str), format, &ts);
            strsubst(str, slist, svalue, j);
            rsputs(str);
         }
         rsprintf("</td></tr>\n");
      }
   }
}

/*------------------------------------------------------------------*/

void show_selection_page()
{
   int i, j, show_title;
   char str[NAME_LENGTH], file_name[256];
   LBLIST phier;

   /* check for Guest Selection Page */
   if (getcfg("global", "Guest Selection Page", str)
       && !(isparam("unm") && isparam("upwd"))) {
      /* check for URL */
      if (strstr(str, "http://")) {
         redirect(NULL, str);
         return;
      }

      /* check if file starts with an absolute directory */
      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strlcpy(file_name, str, sizeof(file_name));
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }
      send_file_direct(file_name);
      return;
   }

   /* top group present and no top group in URL -> abort connection */
   if (exist_top_group() && getcfg_topgroup() == NULL)
      return;

   /* if selection page protected, check password */
   if (getcfg("global", "password file", str))
      if (!check_user_password(NULL, getparam("unm"), getparam("upwd"), ""))
         return;

   if (getcfg("global", "Page Title", str))
      show_html_header(NULL, TRUE, str, TRUE);
   else
      show_html_header(NULL, TRUE, "ELOG Logbook Selection", TRUE);
   rsprintf("<body>\n\n");
   rsprintf("<table class=\"selframe\" cellspacing=0 align=center>\n");
   rsprintf("<tr><td colspan=13 class=\"dlgtitle\">\n");

   if (getcfg("global", "Welcome title", str)) {
      rsputs(str);
   } else {
      rsprintf("%s.<BR>\n", loc("Several logbooks are defined on this host"));
      rsprintf("%s:\n", loc("Please select the one to connect to"));
   }

   rsprintf("</td></tr>\n");

   if (getcfg("global", "mirror server", str)) {

      /* only admin user sees synchronization link */
      if (!getcfg("global", "Admin user", str) || strcmp(str, getparam("unm")) == 0) {
         rsprintf("<tr>\n");
         rsprintf("<td colspan=13 class=\"seltitle\">\n");
         rsprintf("<a href=\"?cmd=Synchronize\">%s</a></td>\n",
                  loc("Synchronize all logbooks"));
         rsprintf("</tr>\n");
      }
   }

   phier = get_logbook_hierarchy();
   show_title = 0;

   if (getcfg_topgroup()) {
      for (i = 0; i < phier->n_members; i++)
         if (equal_ustring(getcfg_topgroup(), phier->member[i]->name)) {
            if (phier->member[i]->n_members == 0)
               show_title = 1;
            else
               for (j = 0; j < phier->member[i]->n_members; j++)
                  if (phier->member[i]->member[j]->n_members == 0)
                     show_title = 1;

            break;
         }
   } else
      for (i = 0; i < phier->n_members; i++) {
         if (phier->member[i]->n_members == 0)
            show_title = 1;
         else
            for (j = 0; j < phier->member[i]->n_members; j++)
               if (phier->member[i]->member[j]->n_members == 0)
                  show_title = 1;
      }


   if (isparam("gexp"))
      show_title = 1;

   if (show_title) {
      rsprintf("<tr>\n");
      rsprintf("<th colspan=10 class=\"seltitle\">%s</th>\n", loc("Logbook"));
      rsprintf("<th class=\"seltitle\">%s</th>\n", loc("Entries"));
      rsprintf("<th class=\"seltitle\">%s</th>\n", loc("Last submission"));
      rsprintf("</tr>\n");
   } else {
      rsprintf("<tr>\n");
      rsprintf("<td colspan=13 class=\"selexp\">\n");
      rsprintf("<a href=\"?gexp=all\">%s</a></td>\n", loc("Expand all"));
      rsprintf("</tr>\n");
   }

   if (getcfg_topgroup()) {
      for (i = 0; i < phier->n_members; i++)
         if (equal_ustring(getcfg_topgroup(), phier->member[i]->name)) {
            show_logbook_node(phier->member[i], NULL, -1, 1);
            break;
         }
   } else
      for (i = 0; i < phier->n_members; i++)
         show_logbook_node(phier->member[i], NULL, 0, 0);

   free_logbook_hierarchy(phier);
   rsprintf("</table></body>\n");
   rsprintf("</html>\r\n\r\n");
}

/*------------------------------------------------------------------*/

void get_password(char *password)
{
   static char last_password[32];

   if (strncmp(password, "set=", 4) == 0)
      strcpy(last_password, password + 4);
   else
      strcpy(password, last_password);
}

/*------------------------------------------------------------------*/

int do_self_register(LOGBOOK * lbs, char *command)
/* evaluate self-registration commands */
{
   char str[256];

   /* display new user page if "self register" is clicked */
   if (equal_ustring(command, loc("New user"))) {
      show_new_user_page(lbs);
      return 0;
   }

   /* save user info if "save" is pressed */
   if (equal_ustring(command, loc("Save")) && isparam("new_user_name")
       && !isparam("config")) {
      if (!save_user_config(lbs, getparam("new_user_name"), TRUE, FALSE))
         return 0;
      if (lbs)
         sprintf(str, "../%s/", lbs->name_enc);
      else
         sprintf(str, ".");
      redirect(lbs, str);
      return 0;
   }

   /* display account request notification */
   if (equal_ustring(command, loc("Requested"))) {
      show_standard_header(lbs, FALSE, loc("ELOG registration"), "");
      rsprintf("<table class=\"dlgframe\" cellspacing=0 align=center>");
      rsprintf("<tr><td colspan=2 class=\"dlgtitle\">\n");
      rsprintf(loc
               ("Your request has been forwarded to the administrator. You will be notified by email upon activation of your new account."));
      rsprintf("</td></tr></table>\n");
      show_bottom_text(lbs);
      rsprintf("</body></html>\n");
      return 0;
   }

   /* indicate continue */
   return 1;
}

/*------------------------------------------------------------------*/

void show_day(char *css_class, char *day)
{
   if (day[0]) {
      rsprintf("<td class=\"%s\" ", css_class);
      rsprintf("onClick='submit_day(\"%s\")' ", day);
      rsprintf("onMouseOver=\"this.className='calsel';\" ");
      rsprintf("onMouseOut=\"this.className='%s';\" ", css_class);
      rsprintf(">%s</td>\n", day);
   } else {
      /* empty cell */
      rsprintf("<td class=\"%s\">&nbsp;</td>\n", css_class);
   }
}

void show_calendar(LOGBOOK * lbs)
{
   int i, j, index, cur_mon, cur_day, cur_year, today_day, today_mon, today_year;
   time_t now, stime;
   struct tm *ts;
   char str[256];

   time(&now);
   ts = localtime(&now);
   today_mon = ts->tm_mon + 1;
   today_day = ts->tm_mday;
   today_year = ts->tm_year + 1900;

   if (isparam("m") && isparam("y")) {
      cur_mon = atoi(getparam("m"));
      cur_year = atoi(getparam("y"));
      cur_day = -1;
      ts->tm_mday = 1;
      ts->tm_mon = cur_mon - 1;
      ts->tm_year = cur_year - 1900;
      mktime(ts);
   } else {
      cur_mon = ts->tm_mon + 1;
      cur_day = ts->tm_mday;
      cur_year = ts->tm_year + 1900;
   }
   if (isparam("i"))
      index = atoi(getparam("i"));
   else
      index = 1;

   show_html_header(lbs, FALSE, loc("Calendar"), TRUE);
   rsprintf("<body class=\"calwindow\"><form name=form1 method=\"GET\" action=\"\">\n");
   rsprintf("<input type=hidden name=\"y\" value=\"%d\">\n", cur_year);

   rsprintf("<script language=\"JavaScript\">\n\n");
   rsprintf("function submit_day(day)\n");
   rsprintf("{\n");
   rsprintf("  opener.document.form1.d%d.value = day;\n", index, cur_year);
   rsprintf("  opener.document.form1.m%d.value = \"%d\";\n", index, cur_mon);
   rsprintf("  opener.document.form1.y%d.value = \"%d\";\n", index, cur_year);
   rsprintf("  window.close();\n");
   rsprintf("}\n");
   rsprintf("</script>\n\n");

   rsprintf("<table border=1 width=300><tr>");
   rsprintf("<td colspan=7 class=\"caltitle\">\n");

   rsprintf("<select name=\"m\" onChange=\"document.form1.submit()\">\n");
   for (i = 0; i < 12; i++)
      if (i + 1 == cur_mon)
         rsprintf("<option selected value=\"%d\">%s\n", i + 1, month_name(i));
      else
         rsprintf("<option value=\"%d\">%s\n", i + 1, month_name(i));
   rsprintf("</select>\n");

   /* link to previous year */
   rsprintf("&nbsp;&nbsp;");
   rsprintf("<a href=\"?i=%d&m=%d&y=%d\">&lt;</a>", index, cur_mon, cur_year - 1);

   /* current year */
   rsprintf("&nbsp;%d&nbsp;", cur_year);

   /* link to next year */
   rsprintf("<a href=\"?i=%d&m=%d&y=%d\">&gt;</a>", index, cur_mon, cur_year + 1);

   /* go to first day of month */
   ts->tm_mday = 1;
   stime = mktime(ts);

   /* go to last sunday */
   stime = stime - 3600 * 24 * ts->tm_wday;

   rsprintf("<tr>\n");
   for (i = 0; i < 7; i++) {
      ts = localtime(&stime);
      strftime(str, sizeof(str), "%a", ts);
      rsprintf("<td class=\"calhead\">%s</td>\n", str);
      stime += 3600 * 24;
   }
   rsprintf("</tr>\n");
   stime -= 3600 * 24 * 7;
   ts = localtime(&stime);

   for (i = 0; i < 6; i++) {
      rsprintf("<tr>\n");

      for (j = 0; j < 7; j++) {
         if (ts->tm_mon + 1 == cur_mon)
            sprintf(str, "%d", ts->tm_mday);
         else
            strcpy(str, "");

         if (ts->tm_mday == today_day && ts->tm_mon + 1 == today_mon
             && ts->tm_year + 1900 == today_year)
            show_day("calcurday", str);
         else {
            if (j == 0)
               show_day("calsun", str);
            else if (j == 6)
               show_day("calsat", str);
            else
               show_day("calday", str);
         }
         stime += 3600 * 24;
         ts = localtime(&stime);
      }

      rsprintf("</tr>\n");
      if (ts->tm_mon + 1 != cur_mon)
         break;
   }

   rsprintf("</form></body></html>\n");
}

/*------------------------------------------------------------------*/

void interprete(char *lbook, char *path)
/********************************************************************\

 Routine: interprete
 
  Purpose: Interprete parametersand generate HTML output.
  
   Input:
   char *path              Message path
   
   <implicit>
   _param/_value array accessible via getparam()
    
\********************************************************************/
{
   int status, i, j, n, index, lb_index, message_id;
   char exp[80], list[1000], section[256], str[NAME_LENGTH], str2[NAME_LENGTH],
       enc_pwd[80], file_name[256], command[80], ref[256], enc_path[256], dec_path[256],
       logbook[256], logbook_enc[256], *experiment, *value, *group, css[256], *pfile,
       attachment[MAX_PATH_LENGTH];
   BOOL global;
   LOGBOOK *lbs;
   FILE *f;

   /* encode path for further usage */
   strcpy(dec_path, path);
   url_decode(dec_path);
   strcpy(enc_path, dec_path);
   url_encode(enc_path, sizeof(enc_path));
   strcpy(command, getparam("cmd"));
   experiment = getparam("exp");
   value = getparam("value");
   group = getparam("group");
   index = atoi(getparam("index"));
   if (getcfg(lbook, "Logging Level", str))
      _logging_level = atoi(str);
   else
      _logging_level = 2;

   /* if experiment given, use it as logbook (for elog!) */
   if (experiment && experiment[0]) {
      strcpy(logbook_enc, experiment);
      strcpy(logbook, experiment);
      url_decode(logbook);
      /* check if logbook exists */
      for (i = 0;; i++) {
         if (!enumgrp(i, str))
            break;
         if (equal_ustring(logbook, str))
            break;
      }
      if (!equal_ustring(logbook, str)) {
         sprintf(str, "Error: logbook \"%s\" not defined in elogd.cfg", logbook);
         show_error(str);
         return;
      }


   } else {
      strcpy(logbook_enc, lbook);
      strcpy(logbook, lbook);
      url_decode(logbook);
   }

   /* check for top group */
   setcfg_topgroup("");

   sprintf(str, "Top group %s", logbook);
   if (getcfg("global", str, list)) {
      setcfg_topgroup(logbook);
      logbook[0] = 0;
   }

   /* check if new logbook */
   for (i = j = 0;; i++) {
      if (!enumgrp(i, str))
         break;

      if (is_logbook(str)) {
         /* redo index if logbooks in cfg file do not match lb_list */
         if (!equal_ustring(str, lb_list[j++].name)) {
            el_index_logbooks(TRUE);
            break;
         }
      }
   }

   /* check for deleted logbook */
   if (lb_list[j].name[0] != 0)
      el_index_logbooks(TRUE);

   /*---- direct commands (registration etc) ----*/

   if (!logbook[0]) {

      /* check for self register */
      if (getcfg(group, "Self register", str) && atoi(str) > 0) {
         if (!do_self_register(NULL, getparam("cmd")))
            return;
      }

      /* check for activate */
      if (equal_ustring(getparam("cmd"), "Activate")) {
         if (!save_user_config(NULL, getparam("new_user_name"), TRUE, TRUE))
            return;
         setparam("cfg_user", getparam("new_user_name"));
         show_config_page(NULL);
         return;
      }

      /* check for save after activate */
      if (equal_ustring(getparam("cmd"), loc("Save"))) {
         if (isparam("config")) {
            /* change existing user */
            if (!save_user_config(NULL, getparam("config"), FALSE, FALSE))
               return;
         }

         redirect(NULL, ".");
         return;
      }

      /* check for password recovery */
      if (isparam("cmd") || isparam("newpwd")) {
         if (equal_ustring(getparam("cmd"), loc("Change password"))
             || isparam("newpwd")) {
            show_change_pwd_page(NULL);
            return;
         }
      }

      /* if data from login screen, evaluate it and set cookies */
      if (*getparam("uname") && getparam("upassword")) {
         /* check if password correct */
         do_crypt(getparam("upassword"), enc_pwd);
         /* log logins */
         logf(NULL, "LOGIN user \"%s\" (attempt) for logbook selection page",
              getparam("uname"));
         if (isparam("redir"))
            strcpy(str, getparam("redir"));
         else
            strcpy(str, getparam("cmdline"));
         if (!check_user_password(NULL, getparam("uname"), enc_pwd, str))
            return;
         logf(NULL, "LOGIN user \"%s\" (success)", getparam("uname"));
         /* set cookies */
         set_login_cookies(NULL, getparam("uname"), enc_pwd);
         return;
      }

      /* check for global selection page if no logbook given */
      if (!logbook[0] && getcfg("global", "Selection page", str)) {
         /* check for URL */
         if (strstr(str, "http://")) {
            redirect(NULL, str);
            return;
         }

         /* check if file starts with an absolute directory */
         if (str[0] == DIR_SEPARATOR || str[1] == ':')
            strlcpy(file_name, str, sizeof(file_name));
         else {
            strlcpy(file_name, resource_dir, sizeof(file_name));
            strlcat(file_name, str, sizeof(file_name));
         }
         send_file_direct(file_name);
         return;
      }

      /* check for global synchronization */
      if (equal_ustring(command, "Synchronize")) {
         synchronize(NULL, FALSE);
         return;
      }

   }

   /* count logbooks */
   for (n = 0; lb_list[n].name[0]; n++);

   /* if no logbook given, display logbook selection page */
   if (!logbook[0] && !path[0]) {
      if (n > 1) {
         show_selection_page(NULL);
         return;
      }

      strcpy(logbook_enc, logbook);
      url_encode(logbook_enc, sizeof(logbook_enc));
   }

   /* get logbook from list */
   for (i = 0; lb_list[i].name[0]; i++)
      if (equal_ustring(logbook, lb_list[i].name))
         break;
   lbs = &lb_list[i];

   /* set top level group for logbook */
   if (lbs->top_group[0])
      setcfg_topgroup(lbs->top_group);

   /* get theme for logbook */
   if (getcfg(logbook, "Theme", str))
      strlcpy(theme_name, str, sizeof(theme_name));
   else
      strlcpy(theme_name, "default", sizeof(theme_name));
   lb_index = i;
   lbs = lb_list + i;
   lbs->n_attr = scan_attributes(lbs->name, NULL);
   if (*getparam("wpassword")) {
      /* check if password correct */
      do_crypt(getparam("wpassword"), enc_pwd);
      if (!check_password(lbs, "Write password", enc_pwd, getparam("redir")))
         return;
      rsprintf("HTTP/1.1 302 Found\r\n");
      rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
      if (use_keepalive) {
         rsprintf("Connection: Keep-Alive\r\n");
         rsprintf("Keep-Alive: timeout=60, max=10\r\n");
      }

      global = getcfg("global", "Write password", str);

      /* get optional expriation from configuration file */
      getcfg(logbook, "Write password expiration", exp);
      /* set "wpwd" cookie */
      set_cookie(lbs, "wpwd", enc_pwd, global, exp);

      /* redirect according to "redir" parameter */
      set_redir(lbs, getparam("redir"));
      return;
   }

   if (*getparam("apassword")) {
      /* check if password correct */
      do_crypt(getparam("apassword"), enc_pwd);
      if (!check_password(lbs, "Admin password", enc_pwd, getparam("redir")))
         return;
      rsprintf("HTTP/1.1 302 Found\r\n");
      rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
      if (use_keepalive) {
         rsprintf("Connection: Keep-Alive\r\n");
         rsprintf("Keep-Alive: timeout=60, max=10\r\n");
      }

      global = getcfg("global", "Admin password", str);

      /* get optional expriation from configuration file */
      getcfg(logbook, "Admin password expiration", exp);
      /* set "apwd" cookie */
      set_cookie(lbs, "apwd", enc_pwd, global, exp);

      /* redirect according to "redir" parameter */
      set_redir(lbs, getparam("redir"));
      return;
   }

   if (*getparam("uname") && getparam("upassword")) {
      /* check if password correct */
      do_crypt(getparam("upassword"), enc_pwd);
      /* log logins */
      logf(lbs, "LOGIN user \"%s\" (attempt)", getparam("uname"));
      if (isparam("redir"))
         strcpy(str, getparam("redir"));
      else
         strcpy(str, getparam("cmdline"));
      if (!check_user_password(lbs, getparam("uname"), enc_pwd, str))
         return;
      logf(lbs, "LOGIN user \"%s\" (success)", getparam("uname"));
      /* set cookies */
      set_login_cookies(lbs, getparam("uname"), enc_pwd);
      return;
   }

   /* if password file given, check password and user name */
   if (getcfg(logbook, "Password file", str)) {
      /* get current CSS */
      strlcpy(css, "default.css", sizeof(css));
      if (lbs != NULL && getcfg(lbs->name, "CSS", str))
         strlcpy(css, str, sizeof(css));
      else if (lbs == NULL && getcfg("global", "CSS", str))
         strlcpy(css, str, sizeof(css));
      /* check if guest access */
      if (!(getcfg(lbs->name, "Guest menu commands", str)
            && *getparam("unm") == 0 && !isparam("wpwd")
            && !isparam("wusr"))) {
         if (strcmp(path, css) != 0) {
            /* if no guest menu commands but self register, evaluate new user commands */
            if (getcfg(lbs->name, "Self register", str) && atoi(str) > 0) {
               if (!do_self_register(lbs, command))
                  return;
            }

            if (!check_user_password
                (lbs, getparam("unm"), getparam("upwd"), getparam("cmdline")))
               return;
         }
      }
   }

   if (equal_ustring(command, loc("Login"))) {
      check_user_password(lbs, "", "", path);
      return;
   }

   if (equal_ustring(command, loc("New")) ||
       equal_ustring(command, loc("Edit")) ||
       equal_ustring(command, loc("Reply")) || equal_ustring(command, loc("Delete"))
       || equal_ustring(command, loc("Upload"))
       || equal_ustring(command, loc("Submit"))) {
      sprintf(str, "%s?cmd=%s", path, command);
      if (!check_password(lbs, "Write password", getparam("wpwd"), str))
         return;
   }

   if (equal_ustring(command, loc("Delete")) || equal_ustring(command, loc("Config"))
       || equal_ustring(command, loc("Copy to"))
       || equal_ustring(command, loc("Move to"))) {
      sprintf(str, "%s?cmd=%s", path, command);
      if (!check_password(lbs, "Admin password", getparam("apwd"), str))
         return;
   }

   /* check for "Back" button */
   if (equal_ustring(command, loc("Back"))
       && getcfg(lbs->name, "Back to main", str)
       && atoi(str) == 1) {
      redirect(lbs, "../");
      return;
   }

   if (equal_ustring(command, loc("Back"))) {
      if (isparam("edit_id")) {
         /* unlock message */
         el_lock_message(lbs, atoi(getparam("edit_id")), NULL);
         /* redirect to message */
         sprintf(str, "../%s/%s", logbook_enc, getparam("edit_id"));
      } else
         sprintf(str, "../%s/", logbook_enc);
      redirect(lbs, str);
      return;
   }

   /* check for "Cancel" button */
   if (equal_ustring(command, loc("Cancel"))) {
      sprintf(str, "../%s/%s", logbook_enc, path);
      redirect(lbs, str);
      return;
   }

   /* check for "Last n*2 Entries" */
   strcpy(str, getparam("last"));
   if (strchr(str, ' ')) {
      i = atoi(strchr(str, ' '));
      sprintf(str, "last%d", i);
      if (isparam("mode"))
         sprintf(str + strlen(str), "?mode=%s", getparam("mode"));
      redirect(lbs, str);
      return;
   }

   strcpy(str, getparam("past"));
   if (strchr(str, ' ')) {
      i = atoi(strchr(str, ' '));
      sprintf(str, "past%d", i);
      redirect(lbs, str);
      return;
   }

   /* check for lastxx and pastxx and listxx */
   if (strncmp(path, "past", 4) == 0 && isdigit(path[4]) && *getparam("cmd") == 0) {
      show_elog_list(lbs, atoi(path + 4), 0, 0);
      return;
   }

   if (strncmp(path, "last", 4) == 0 && strstr(path, ".gif") == NULL &&
       (!isparam("cmd") || equal_ustring(getparam("cmd"), loc("Select")))
       && !isparam("newpwd")) {
      show_elog_list(lbs, 0, atoi(path + 4), 0);
      return;
   }

   if (strncmp(path, "page", 4) == 0 && *getparam("cmd") == 0) {
      if (!path[4])
         show_elog_list(lbs, 0, 0, -1);
      else
         show_elog_list(lbs, 0, 0, atoi(path + 4));
      return;
   }

   /*---- check if file requested -----------------------------------*/

   /* skip elog message id in front of possible attachment */
   pfile = dec_path;
   if (strchr(pfile, '/') && pfile[13] != '/' && isdigit(pfile[0]))
      pfile = strchr(pfile, '/') + 1;

   if ((strlen(pfile) > 13 && pfile[6] == '_' && pfile[13] == '_')
       || (strlen(pfile) > 13 && pfile[6] == '_' && pfile[13] == '/')
       || strstr(pfile, ".gif")
       || strstr(pfile, ".jpg") || strstr(pfile, ".jpeg")
       || strstr(pfile, ".png") || strstr(pfile, ".css")
       || strstr(pfile, ".js")) {
      if ((strlen(pfile) > 13 && pfile[6] == '_'
           && pfile[13] == '_') || (strlen(pfile) > 13 && pfile[6] == '_'
                                    && pfile[13] == '/')) {
         if (pfile[13] == '/')
            pfile[13] = '_';
         /* file from data directory requested */
         strlcpy(file_name, lbs->data_dir, sizeof(file_name));
         strlcat(file_name, pfile, sizeof(file_name));
      } else {
         /* file from theme directory requested */
         strlcpy(file_name, resource_dir, sizeof(file_name));
         if (file_name[0]
             && file_name[strlen(file_name)
                          - 1] != DIR_SEPARATOR)
            strlcat(file_name, DIR_SEPARATOR_STR, sizeof(file_name));
         strlcat(file_name, "themes", sizeof(file_name));
         strlcat(file_name, DIR_SEPARATOR_STR, sizeof(file_name));
         if (theme_name[0]) {
            strlcat(file_name, theme_name, sizeof(file_name));
            strlcat(file_name, DIR_SEPARATOR_STR, sizeof(file_name));
         }
         strlcat(file_name, pfile, sizeof(file_name));
      }

      send_file_direct(file_name);
      return;
   }

   /*---- check if attachment requested -----------------------------*/

   if (strchr(dec_path, '/')) {
      message_id = atoi(dec_path);
      n = atoi(strchr(dec_path, '/') + 1) - 1;
      status = el_retrieve_attachment(lbs, message_id, n, attachment);
      if (status != EL_SUCCESS || n >= MAX_ATTACHMENTS) {
         sprintf(str, "Attachment #%d of entry #%d not found", n + 1, message_id);
         show_error(str);
      } else {
         redirect(lbs, attachment);
      }

      return;
   }

   /* check for new syntax in elogd.cfg */
   if (getcfg(lbs->name, "Types", str)) {
      show_upgrade_page(lbs);
      return;
   }

   /* correct for image buttons */
   if (*getparam("cmd_first.x"))
      strcpy(command, loc("First"));
   if (*getparam("cmd_previous.x"))
      strcpy(command, loc("Previous"));
   if (*getparam("cmd_next.x"))
      strcpy(command, loc("Next"));
   if (*getparam("cmd_last.x"))
      strcpy(command, loc("Last"));
   /* check if command allowed for current user */
   if (command[0] && !is_user_allowed(lbs, command)) {
      sprintf(str,
              loc
              ("Error: Command \"<b>%s</b>\" is not allowed for user \"<b>%s</b>\""),
              command, getparam("full_name"));
      show_error(str);
      return;
   }

   /* check if command in menu list */
   if (!is_command_allowed(lbs, command)) {
      sprintf(str, loc("Error: Command \"<b>%s</b>\" not allowed"), command);
      show_error(str);
      return;
   }

   /*---- check for various commands --------------------------------*/

   if (equal_ustring(command, loc("Help"))) {
      if (getcfg(lbs->name, "Help URL", str)) {
         /* if file is given, add '/' to make absolute path */
         if (strchr(str, '/') == NULL)
            sprintf(ref, "/%s", str);
         else
            strcpy(ref, str);
         redirect(lbs, ref);
         return;
      }

      /* send local help file */
      strlcpy(file_name, resource_dir, sizeof(file_name));
      strlcat(file_name, "eloghelp_", sizeof(file_name));
      if (getcfg("global", "Language", str)) {
         str[2] = 0;
         strlcat(file_name, str, sizeof(file_name));
      } else
         strlcat(file_name, "en", sizeof(file_name));
      strlcat(file_name, ".html", sizeof(file_name));
      f = fopen(file_name, "r");
      if (f == NULL)
         redirect(lbs, "http://midas.psi.ch/elog/eloghelp_en.html");
      else {
         fclose(f);
         send_file_direct(file_name);
      }
      return;
   }

   if (equal_ustring(command, loc("New"))) {
      show_edit_form(lbs, 0, FALSE, FALSE, FALSE, FALSE);
      return;
   }

   message_id = atoi(dec_path);
   if (equal_ustring(command, loc("Upload"))) {
      show_edit_form(lbs, atoi(getparam("edit_id")), FALSE, TRUE, TRUE, FALSE);
      return;
   }

   /* check for deletion of attachments */
   for (i = 0; i < MAX_ATTACHMENTS; i++) {
      sprintf(str, "delatt%d", i);
      if (isparam(str)) {
         sprintf(str, "attachment%d", i);
         strlcpy(file_name, getparam(str), sizeof(file_name));
         el_delete_attachment(lbs, file_name);
         /* re-order attachments */
         for (j = i; j < MAX_ATTACHMENTS; j++) {
            sprintf(str, "attachment%d", j + 1);
            if (isparam(str))
               strlcpy(file_name, getparam(str), sizeof(file_name));
            else
               file_name[0] = 0;
            sprintf(str, "attachment%d", j);
            if (file_name[0])
               setparam(str, file_name);
            else
               unsetparam(str);
         }

         show_edit_form(lbs, atoi(getparam("edit_id")), FALSE, TRUE, TRUE, FALSE);
         return;
      }
   }

   if (equal_ustring(command, loc("Edit"))) {
      if (message_id) {
         show_edit_form(lbs, message_id, FALSE, TRUE, FALSE, FALSE);
         return;
      }
   }

   if (equal_ustring(command, loc("Reply"))) {
      show_edit_form(lbs, message_id, TRUE, FALSE, FALSE, FALSE);
      return;
   }

   if (equal_ustring(command, loc("Update"))) {
      show_edit_form(lbs, atoi(getparam("edit_id")), FALSE, TRUE, FALSE, TRUE);
      return;
   }

   if (equal_ustring(command, loc("Submit"))
       || equal_ustring(command, "Submit")) {

      if (isparam("mirror_id"))
         submit_elog_mirror(lbs);
      else
         submit_elog(lbs);
      return;
   }

   if (equal_ustring(command, loc("Find"))) {
      /* stip message id */
      if (dec_path[0]) {
         sprintf(str, "../%s/?cmd=%s", lbs->name_enc, loc("Find"));
         redirect(lbs, str);
         return;
      }
      show_find_form(lbs);
      return;
   }

   if (equal_ustring(command, loc("Search"))) {
      if (dec_path[0] && atoi(dec_path) == 0 && strchr(dec_path, '/') != NULL) {
         sprintf(str, "Invalid URL: <b>%s</b>", dec_path);
         show_error(str);
         return;
      }

      show_elog_list(lbs, 0, 0, 1);
      return;
   }

   if (equal_ustring(command, loc("Last day"))) {
      redirect(lbs, "past1");
      return;
   }

   if (equal_ustring(command, loc("Last 10"))) {
      redirect(lbs, "last10");
      return;
   }

   if (equal_ustring(command, loc("Copy to"))) {
      copy_to(lbs, message_id, getparam("destc"), 0, 0);
      return;
   }

   if (equal_ustring(command, loc("Move to"))) {
      copy_to(lbs, message_id, getparam("destm"), 1, 0);
      return;
   }

   if (equal_ustring(command, loc("Admin"))
       || equal_ustring(command, loc("Change elogd.cfg"))) {
      show_admin_page(lbs, NULL);
      return;
   }

   sprintf(str, loc("Change %s"), "[global]");
   if (equal_ustring(command, str)) {
      show_admin_page(lbs, "global");
      return;
   }

   sprintf(str2, "[global %s]", lbs->top_group);
   sprintf(str, loc("Change %s"), str2);
   if (equal_ustring(command, str)) {
      show_admin_page(lbs, lbs->top_group);
      return;
   }

   if (equal_ustring(command, loc("Change password"))
       || (isparam("newpwd") && !equal_ustring(command, loc("Cancel"))
           && !equal_ustring(command, loc("Save")))) {
      show_change_pwd_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("Save"))) {
      if (isparam("config")) {
         if (!equal_ustring(getparam("config"), getparam("new_user_name"))) {
            if (get_user_line
                (lbs->name, getparam("new_user_name"), NULL, NULL, NULL, NULL) == 1) {
               sprintf(str, "%s \"%s\" %s", loc("Login name"),
                       getparam("new_user_name"), loc("exists already"));
               show_error(str);
               return;
            }
         }

         /* change existing user */
         if (!save_user_config(lbs, getparam("config"), FALSE, FALSE))
            return;
      } else if (isparam("new_user_name")) {
         /* new user */
         if (!save_user_config(lbs, getparam("new_user_name"), TRUE, FALSE))
            return;
      } else {

         if (isparam("global")) {
            if (equal_ustring(getparam("global"), "global"))
               strcpy(section, "global");
            else
               sprintf(section, "global %s", getparam("global"));
         } else
            strlcpy(section, lbs->name, sizeof(section));

         if (!save_admin_config(lbs, section, _mtext, str)) {   /* save cfg file */
            show_error(str);
            return;
         }
      }
      if (lbs)
         sprintf(str, "../%s/", lbs->name_enc);
      else
         sprintf(str, ".");
      if (isparam("new_user_name"))
         sprintf(str + strlen(str), "?cmd=%s&cfg_user=%s", loc("Config"),
                 getparam("new_user_name"));
      else if (isparam("cfg_user"))
         sprintf(str + strlen(str), "?cmd=%s&cfg_user=%s", loc("Config"),
                 getparam("cfg_user"));
      else if (getcfg(lbs->name, "password file", str2))
         sprintf(str + strlen(str), "?cmd=%s", loc("Config"));

      redirect(lbs, str);
      return;
   }

   if (equal_ustring(command, "Activate")) {
      if (!save_user_config(lbs, getparam("new_user_name"), TRUE, TRUE))
         return;
      setparam("cfg_user", getparam("new_user_name"));
      show_config_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("Remove user"))) {
      remove_user(lbs, getparam("config"));
      /* if removed user is current user, do logout */
      if (equal_ustring(getparam("config"), getparam("unm"))) {
         /* log activity */
         logf(lbs, "LOGOUT");
         /* set cookies */
         set_login_cookies(lbs, "", "");
      }

      /* continue configuration as administrator */
      unsetparam("cfg_user");
      show_config_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("New user"))) {
      show_new_user_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("Forgot"))) {
      show_forgot_pwd_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("Config"))) {
      if (!getcfg(lbs->name, "Password file", str))
         show_admin_page(lbs, NULL);
      else
         show_config_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("Download"))
       || equal_ustring(command, "Download")) {
      show_download_page(lbs, dec_path);
      return;
   }

   if (equal_ustring(command, "getmd5")) {
      show_md5_page(lbs);
      return;
   }

   if (equal_ustring(command, loc("Synchronize"))) {
      synchronize(lbs, FALSE);
      return;
   }

   if (equal_ustring(command, loc("Logout"))) {
      /* log activity */
      logf(lbs, "LOGOUT");
      if (getcfg(lbs->name, "Logout to main", str) && atoi(str) == 1) {
         sprintf(str, "../");
         setparam("redir", str);
      }
      set_login_cookies(lbs, "", "");
      return;
   }

   if (equal_ustring(command, loc("Delete"))) {
      show_elog_delete(lbs, message_id);
      return;
   }

   /* check for welcome page */
   if (!_cmdline[0] && getcfg(lbs->name, "Welcome page", str) && str[0]) {
      /* check if file starts with an absolute directory */
      if (str[0] == DIR_SEPARATOR || str[1] == ':')
         strcpy(file_name, str);
      else {
         strlcpy(file_name, resource_dir, sizeof(file_name));
         strlcat(file_name, str, sizeof(file_name));
      }
      send_file_direct(file_name);
      return;
   }

   /* check for start page */
   if (!_cmdline[0] && getcfg(lbs->name, "Start page", str) && str[0]) {
      redirect(lbs, str);
      return;
   }

   /* check for calender */
   if (equal_ustring(dec_path, "cal.html")) {
      show_calendar(lbs);
      return;
   }

   /* show page listing or display single entry */
   if (dec_path[0] == 0)
      show_elog_list(lbs, 0, 0, 1);
   else
      show_elog_message(lbs, dec_path, command);
   return;
}

/*------------------------------------------------------------------*/

void decode_get(char *logbook, char *string)
{
   char path[256];
   char *p, *pitem;

   setparam("cmdline", string);
   strlcpy(path, string, sizeof(path));
   path[255] = 0;
   if (strchr(path, '?'))
      *strchr(path, '?') = 0;
   setparam("path", path);
   if (strchr(string, '?')) {
      p = strchr(string, '?') + 1;
      /* cut trailing "/" from netscape */
      if (p[strlen(p) - 1] == '/')
         p[strlen(p) - 1] = 0;
      p = strtok(p, "&");
      while (p != NULL) {
         pitem = p;
         p = strchr(p, '=');
         if (p != NULL) {
            *p++ = 0;
            url_decode(pitem);
            url_decode(p);
            setparam(pitem, p);
            p = strtok(NULL, "&");
         }
      }
   }

   interprete(logbook, path);
}

/*------------------------------------------------------------------*/

void decode_post(LOGBOOK * lbs, char *string, char *boundary, int length)
{
   int n_att;
   char *pinit, *p, *ptmp, file_name[256], full_name[256], str[NAME_LENGTH],
       line[NAME_LENGTH], item[NAME_LENGTH];
   n_att = 0;
   pinit = string;
   /* return if no boundary defined */
   if (!boundary[0])
      return;
   if (strstr(string, boundary))
      string = strstr(string, boundary) + strlen(boundary);
   do {
      if (strstr(string, "name=")) {
         strlcpy(line, strstr(string, "name=") + 5, sizeof(line));
         if (strchr(line, '\r'))
            *strchr(line, '\r') = 0;
         if (strchr(line, '\n'))
            *strchr(line, '\n') = 0;
         strcpy(item, line);
         if (item[0] == '\"') {
            strcpy(item, line + 1);
            if (strchr(item, '\"'))
               *strchr(item, '\"') = 0;
         } else if (strchr(item, ' '))
            *strchr(item, ' ') = 0;
         if (strncmp(item, "attachment", 10) == 0) {
            /* attachment names from previous uploads */
            n_att = atoi(item + 10) + 1;
         }

         if (strncmp(item, "attfile", 7) == 0) {
            /* evaluate file attachment */
            if (strstr(string, "filename=")) {
               p = strstr(string, "filename=") + 9;
               if (*p == '\"')
                  p++;
               if (strstr(p, "\r\n\r\n"))
                  string = strstr(p, "\r\n\r\n") + 4;
               else if (strstr(p, "\r\r\n\r\r\n"))
                  string = strstr(p, "\r\r\n\r\r\n") + 6;
               if (strchr(p, '\"'))
                  *strchr(p, '\"') = 0;
               /* set attachment filename */
               strcpy(file_name, p);
               if (file_name[0]) {
                  if (verbose)
                     printf("decode_post: Found attachment %s\n", file_name);
                  /* check filename for invalid characters */
                  if (strpbrk(file_name, ",;")) {
                     sprintf(str, "Error: Filename \"%s\" contains invalid character",
                             file_name);
                     show_error(str);
                     return;
                  }
               }

               /* find next boundary */
               ptmp = string;
               do {
                  while (*ptmp != '-')
                     ptmp++;
                  if ((p = strstr(ptmp, boundary)) != NULL) {
                     if (*(p - 1) == '-')
                        p--;
                     while (*p == '-')
                        p--;
                     if (*p == 10)
                        p--;
                     if (*p == 13)
                        p--;
                     p++;
                     break;
                  } else
                     ptmp += strlen(ptmp);
               } while (TRUE);
               /* save attachment */
               if (file_name[0]) {
                  el_submit_attachment(lbs, file_name, string, (int) (p - string),
                                       full_name);
                  sprintf(str, "attachment%d", n_att++);
                  setparam(str, full_name);
               }

               string = strstr(p, boundary) + strlen(boundary);
            } else
               string = strstr(string, boundary) + strlen(boundary);
         } else {
            p = string;
            if (strstr(p, "\r\n\r\n"))
               p = strstr(p, "\r\n\r\n") + 4;
            else if (strstr(p, "\r\r\n\r\r\n"))
               p = strstr(p, "\r\r\n\r\r\n") + 6;
            if (strstr(p, boundary)) {
               string = strstr(p, boundary) + strlen(boundary);
               *strstr(p, boundary) = 0;
               ptmp = p + (strlen(p) - 1);
               while (*ptmp == '-')
                  *ptmp-- = 0;
               while (*ptmp == '\n' || *ptmp == '\r')
                  *ptmp-- = 0;
            }

            if (setparam(item, p) == 0)
               return;
         }

         while (*string == '-' || *string == '\n' || *string == '\r')
            string++;
      }

   }
   while ((int) (string - pinit) < length);
   interprete(lbs->name, "");
}

/*------------------------------------------------------------------*/

BOOL cron_match(char *str, int value, BOOL ignore_star)
{
   int low, high;

   if (atoi(str) == value)
      return TRUE;

   if (!ignore_star && str[0] == '*')
      return TRUE;

   /* check range */
   if (strchr(str, '-')) {
      low = atoi(str);
      high = atoi(strchr(str, '-') + 1);
      return value >= low && value <= high;
   }

   return FALSE;
}

void check_cron()
/* check 'mirror cron' etnry in configuration file

   minute         (0-59)
   hour           (0-23)
   day of month   (1-31)
   month of year  (1-12)
   day of week    (0-6, 0 is Sunday)

   Each of these patterns might be an asterisk (meaning all legal values)
   or a list of elements separated by commas.
*/
{
   int i, j, n;
   BOOL min_flag, hour_flag, day_flag, mon_flag, wday_flag;
   time_t now;
   char *p, str[256], cron[5][256];
   struct tm *ts;
   static struct tm last_time;
   char list[60][NAME_LENGTH];

   if (!getcfg("global", "mirror cron", str))
      return;

   for (i = 0; i < 5; i++)
      strcpy(cron[i], "*");

   i = 0;
   p = strtok(str, " ");
   while (p) {
      strcpy(cron[i++], p);
      p = strtok(NULL, " ");
   }

   time(&now);
   ts = localtime(&now);

   /* check once every minute */
   if (last_time.tm_year && last_time.tm_min != ts->tm_min) {

      min_flag = hour_flag = day_flag = mon_flag = wday_flag = FALSE;

      for (i = 0; i < 5; i++) {
         n = strbreak(cron[i], list, 60);

         for (j = 0; j < n; j++) {
            /* minutes */
            if (i == 0 && cron_match(list[j], ts->tm_min, FALSE))
               min_flag = TRUE;

            /* hours */
            if (i == 1 && cron_match(list[j], ts->tm_hour, FALSE))
               hour_flag = TRUE;

            /* day of month */
            if (i == 2 && cron_match(list[j], ts->tm_mday, FALSE))
               day_flag = TRUE;

            /* month of year */
            if (i == 3 && cron_match(list[j], ts->tm_mon, FALSE))
               mon_flag = TRUE;

            /* weekday */
            if (i == 4 && cron_match(list[j], ts->tm_wday, TRUE))
               wday_flag = TRUE;
         }
      }

      if (min_flag && hour_flag && ((day_flag && mon_flag) || wday_flag)) {

         rem_host[0] = 0;
         logf(NULL, "Cron job started");

         /* synchronize all logbooks */
         setcfg_topgroup("");
         synchronize(NULL, TRUE);
      }
   }


   memcpy(&last_time, ts, sizeof(struct tm));
}

/*------------------------------------------------------------------*/

BOOL _abort = FALSE;
BOOL _hup = FALSE;

void ctrlc_handler(int sig)
{
   _abort = TRUE;
}

void hup_handler(int sig)
{
   _hup = TRUE;
}

/*------------------------------------------------------------------*/

#define N_MAX_CONNECTION 10
#define KEEP_ALIVE_TIME  60

int ka_sock[N_MAX_CONNECTION];
int ka_time[N_MAX_CONNECTION];
struct in_addr remote_addr[N_MAX_CONNECTION];
char remote_host[N_MAX_CONNECTION][256];
void server_loop(int tcp_port, int daemon)
{
   int status, i, n, n_error, authorized, min, i_min, i_conn, length;
   struct sockaddr_in serv_addr, acc_addr;
   char pwd[256], str[256], url[256], cl_pwd[256], *p, *pd;
   char cookie[256], boundary[256], list[1000], theme[256],
       host_list[MAX_N_LIST][NAME_LENGTH], rem_host_ip[256], logbook[256],
       logbook_enc[256];
   int lsock, len, flag, content_length, header_length;
   struct hostent *phe;
   fd_set readfds;
   struct timeval timeout;
   char *net_buffer = NULL;
   int net_buffer_size;

   net_buffer_size = 100000;
   net_buffer = malloc(net_buffer_size);
   return_buffer_size = 100000;
   return_buffer = malloc(return_buffer_size);
#ifdef OS_WINNT
   {
      WSADATA WSAData;

      /* Start windows sockets */
      if (WSAStartup(MAKEWORD(1, 1), &WSAData) != 0)
         return;
   }
#endif

   /* create a new socket */
   lsock = socket(AF_INET, SOCK_STREAM, 0);
   if (lsock == -1) {
      printf("Cannot create socket\n");
      return;
   }

   /* bind local node name and port to socket */
   memset(&serv_addr, 0, sizeof(serv_addr));
   serv_addr.sin_family = AF_INET;
   /* if no hostname given with the -h flag, listen on any interface */
   if (tcp_hostname[0] == 0)
      serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
   else {
      /* look up the given hostname. gethostbyname() will take a hostname
         or an IP address */
      phe = gethostbyname(tcp_hostname);
      if (!phe) {
         printf("Cannot find address for -h %s\n", tcp_hostname);
         return;
      }
      if (phe->h_addrtype != AF_INET) {
         printf("Non Internet address for -h %s\n", tcp_hostname);
         return;
      }
      memcpy(&serv_addr.sin_addr.s_addr, phe->h_addr_list[0], phe->h_length);
   }

   serv_addr.sin_port = htons((short) tcp_port);
   /* try reusing address */
   flag = 1;
   setsockopt(lsock, SOL_SOCKET, SO_REUSEADDR, (char *) &flag, sizeof(INT));
   status = bind(lsock, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
   if (status < 0) {
      printf
          ("Cannot bind to port %d.\nPlease try later or use the \"-p\" flag to specify a different port\n",
           tcp_port);
      return;
   }

   /* get host name for mail notification */
   gethostname(host_name, sizeof(host_name));
   phe = gethostbyname(host_name);
   if (phe != NULL)
      phe = gethostbyaddr(phe->h_addr, sizeof(int), AF_INET);
   /* if domain name is not in host name, hope to get it from phe */
   if (strchr(host_name, '.') == NULL && phe != NULL)
      strcpy(host_name, phe->h_name);
   /* open configuration file */
   getcfg("dummy", "dummy", str);
   /* initiate daemon */
   if (daemon) {
      printf("Becoming a daemon...\n");
      ss_daemon_init();
   }
#ifdef OS_UNIX
   /* create PID file if given as command line parameter or if running under root */

   if (geteuid() == 0 || pidfile[0]) {
      int fd;
      char buf[20];
      struct stat finfo;

      if (pidfile[0] == 0)
         strcpy(pidfile, PIDFILE);
      /* check if file exists */
      if (stat(pidfile, &finfo) >= 0) {
         printf("File \"%s\" exists, using \"%s.%d\" instead.\n", pidfile, pidfile,
                tcp_port);
         sprintf(pidfile + strlen(pidfile), ".%d", tcp_port);
         /* check again for the new name */
         if (stat(pidfile, &finfo) >= 0) {
            /* never overwrite a file */
            printf("Refuse to overwrite existing file \"%s\".\n", pidfile);
            exit(EXIT_FAILURE);
         }
      }

      fd = open(pidfile, O_CREAT | O_RDWR, 0644);
      if (fd < 0) {
         sprintf(str, "Error creating pid file \"%s\"", pidfile);
         perror(str);
         exit(EXIT_FAILURE);
      }

      sprintf(buf, "%d\n", (int) getpid());
      if (write(fd, buf, strlen(buf)) == -1) {
         sprintf(str, "Error writing to pid file \"%s\"", pidfile);
         perror(str);
         exit(EXIT_FAILURE);
      }
      close(fd);
   }

   /* install signal handler */
   signal(SIGTERM, ctrlc_handler);
   signal(SIGINT, ctrlc_handler);
   signal(SIGPIPE, SIG_IGN);
   signal(SIGHUP, hup_handler);
   /* give up root privilege */
   if (geteuid() == 0) {
      if (!getcfg("global", "Grp", str) || setgroup(str) < 0) {
         printf("Falling back to default group \"elog\"\n");
         if (setgroup("elog") < 0) {
            printf("Falling back to default group \"%s\"\n", DEFAULT_GROUP);
            if (setgroup(DEFAULT_GROUP) < 0) {
               printf("Refuse to run as setgid root.\n");
               printf
                   ("Please consider to define a Grp statement in configuration file\n");
               exit(EXIT_FAILURE);
            }
         }
      }

      if (!getcfg("global", "Usr", str) || setuser(str) < 0) {
         printf("Falling back to default user \"elog\"\n");
         if (setuser("elog") < 0) {
            printf("Falling back to default user \"%s\"\n", DEFAULT_USER);
            if (setuser(DEFAULT_USER) < 0) {
               printf("Refuse to run as setuid root.\n");
               printf
                   ("Please consider to define a Usr statement in configuration file\n");
               exit(EXIT_FAILURE);
            }
         }
      }
   }
#endif

   /* load initial configuration */
   check_config();
   /* build logbook indices */
   if (el_index_logbooks(FALSE) != EL_SUCCESS)
      exit(EXIT_FAILURE);
   /* listen for connection */
   status = listen(lsock, SOMAXCONN);
   if (status < 0) {
      printf("Cannot listen\n");
      return;
   }

   printf("Server listening on port %d...\n", tcp_port);
   do {
      FD_ZERO(&readfds);
      FD_SET(lsock, &readfds);
      for (i = 0; i < N_MAX_CONNECTION; i++)
         if (ka_sock[i] > 0)
            FD_SET(ka_sock[i], &readfds);
      timeout.tv_sec = 1;
      timeout.tv_usec = 0;
      status = select(FD_SETSIZE, (void *) &readfds, NULL, NULL, (void *) &timeout);

      /* check UNIX signal flags */
      if (_abort)
         break;

      if (FD_ISSET(lsock, &readfds)) {
         len = sizeof(acc_addr);
         _sock = accept(lsock, (struct sockaddr *) &acc_addr, &len);
         /* find new entry in socket table */
         for (i = 0; i < N_MAX_CONNECTION; i++)
            if (ka_sock[i] == 0)
               break;
         /* recycle last connection */
         if (i == N_MAX_CONNECTION) {
            for (i = i_min = 0, min = ka_time[0]; i < N_MAX_CONNECTION; i++)
               if (ka_time[i] < min) {
                  min = ka_time[i];
                  i_min = i;
               }

            closesocket(ka_sock[i_min]);
            ka_sock[i_min] = 0;
            i = i_min;
#ifdef DEBUG_CONN
            printf("## close connection %d\n", i_min);
#endif
         }

         i_conn = i;
         ka_sock[i_conn] = _sock;
         ka_time[i_conn] = (int) time(NULL);
         /* save remote host address */
         memcpy(&remote_addr[i_conn], &(acc_addr.sin_addr), sizeof(rem_addr));
         memcpy(&rem_addr, &(acc_addr.sin_addr), sizeof(rem_addr));
         phe = gethostbyaddr((char *) &rem_addr, 4, PF_INET);
         if (phe != NULL)
            strcpy(remote_host[i_conn], phe->h_name);
         else
            strcpy(remote_host[i_conn], (char *) inet_ntoa(rem_addr));
         strcpy(rem_host, remote_host[i_conn]);
#ifdef DEBUG_CONN
         printf("## open new connection %d\n", i_conn);
#endif
      }

      else {
         /* check if open connection received data */
         for (i = 0; i < N_MAX_CONNECTION; i++)
            if (ka_sock[i] > 0 && FD_ISSET(ka_sock[i], &readfds))
               break;
         if (i == N_MAX_CONNECTION) {
            _sock = 0;
         } else {
            i_conn = i;
            _sock = ka_sock[i_conn];
            ka_time[i_conn] = (int) time(NULL);
            memcpy(&rem_addr, &remote_addr[i_conn], sizeof(rem_addr));
            strcpy(rem_host, remote_host[i_conn]);
#ifdef DEBUG_CONN
            printf("## received request on connection %d\n", i_conn);
#endif
         }
      }

      /* turn off keep_alive by default */
      keep_alive = FALSE;
      if (_sock > 0) {
         memset(net_buffer, 0, net_buffer_size);
         len = 0;
         header_length = 0;
         n_error = 0;
         do {
            FD_ZERO(&readfds);
            FD_SET(_sock, &readfds);
            timeout.tv_sec = 6;
            timeout.tv_usec = 0;
            status = select(FD_SETSIZE, (void *) &readfds, NULL, NULL, (void *) &timeout);
            if (FD_ISSET(_sock, &readfds))
               i = recv(_sock, net_buffer + len, net_buffer_size - len, 0);
            else
               goto finished;
            /* abort if connection got broken */
            if (i < 0)
               goto finished;
            if (i > 0)
               len += i;
            /* check if net_buffer needs to be increased */
            if (len == net_buffer_size) {
               net_buffer = realloc(net_buffer, net_buffer_size + 100000);
               if (net_buffer == NULL) {
                  sprintf(str,
                          "Error: Cannot increase net_buffer, out of memory, net_buffer_size = %d",
                          net_buffer_size);
                  show_error(str);
                  send(_sock, return_buffer, strlen_retbuf + 1, 0);
                  keep_alive = 0;
                  if (verbose) {
                     printf("==== Return ================================\n");
                     puts(return_buffer);
                     printf("\n\n");
                  }
                  goto finished;
               }

               memset(net_buffer + net_buffer_size, 0, 100000);
               net_buffer_size += 100000;
            }

            if (i == 0) {
               n_error++;
               if (n_error == 100)
                  goto finished;
            }

            /* finish when empty line received */
            if (strstr(net_buffer, "GET") != NULL && strstr(net_buffer, "POST") == NULL) {
               if (len > 4 && strcmp(&net_buffer[len - 4], "\r\n\r\n") == 0)
                  break;
               if (len > 6 && strcmp(&net_buffer[len - 6], "\r\r\n\r\r\n") == 0)
                  break;
            } else if (strstr(net_buffer, "POST") != NULL) {
               if (header_length == 0) {
                  /* extract logbook */
                  strlcpy(str, net_buffer + 6, sizeof(str));
                  if (strstr(str, "HTTP"))
                     *(strstr(str, "HTTP") - 1) = 0;
                  strlcpy(logbook, str, sizeof(logbook));
                  strlcpy(logbook_enc, str, sizeof(logbook));
                  url_decode(logbook);
                  /* extract header and content length */
                  if (strstr(net_buffer, "Content-Length:"))
                     content_length = atoi(strstr(net_buffer, "Content-Length:") + 15);
                  else if (strstr(net_buffer, "Content-length:"))
                     content_length = atoi(strstr(net_buffer, "Content-length:") + 15);
                  boundary[0] = 0;
                  if (strstr(net_buffer, "boundary=")) {
                     strlcpy(boundary, strstr(net_buffer, "boundary=") + 9,
                             sizeof(boundary));
                     if (strchr(boundary, '\r'))
                        *strchr(boundary, '\r') = 0;
                  }

                  if (strstr(net_buffer, "\r\n\r\n"))
                     header_length =
                         (INT) strstr(net_buffer, "\r\n\r\n") - (INT) net_buffer + 4;
                  if (strstr(net_buffer, "\r\r\n\r\r\n"))
                     header_length =
                         (INT) strstr(net_buffer, "\r\r\n\r\r\n") - (INT) net_buffer + 6;
                  if (header_length)
                     net_buffer[header_length - 1] = 0;
               }

               if (header_length > 0 && len >= header_length + content_length)
                  break;
            } else if (strstr(net_buffer, "HEAD") != NULL) {
               /* just return header */
               rsprintf("HTTP/1.1 200 OK\r\n");
               rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
               rsprintf("Connection: close\r\n");
               rsprintf("Content-Type: text/html\r\n\r\n");
               keep_alive = FALSE;
               return_length = strlen_retbuf + 1;
               send(_sock, return_buffer, return_length, 0);
               goto finished;
            } else if (strstr(net_buffer, "OPTIONS") != NULL)
               goto finished;
            else {
               puts(net_buffer);
               goto finished;
            }

         } while (1);
         if (!strchr(net_buffer, '\r'))
            goto finished;
         if (verbose) {
            puts("\n");
            puts(net_buffer);
         }

         /* initialize parametr array */
         initparam();
         /* extract cookies */
         if ((p = strstr(net_buffer, "Cookie:")) != NULL) {
            p += 6;
            do {
               p++;
               while (*p && *p == ' ')
                  p++;
               strlcpy(str, p, sizeof(str));
               for (i = 0; i < (int) strlen(str); i++)
                  if (str[i] == '=' || str[i] == ';')
                     break;
               if (str[i] == '=') {
                  str[i] = 0;
                  p += i + 1;
                  for (i = 0; *p && *p != ';' && *p != '\r' && *p != '\n'; i++)
                     cookie[i] = *p++;
                  cookie[i] = 0;
               } else {
                  /* empty cookie */
                  str[i] = 0;
                  cookie[0] = 0;
                  p += i;
               }

               /* store cookie as parameter */
               setparam(str, cookie);
            } while (*p && *p == ';');
         }

         /* extract referer */
         referer[0] = 0;
         if ((p = strstr(net_buffer, "Referer:")) != NULL) {
            p += 9;
            while (*p && *p == ' ')
               p++;
            strlcpy(referer, p, sizeof(referer));
            if (strchr(referer, '\r'))
               *strchr(referer, '\r') = 0;
            if (strchr(referer, '?'))
               *strchr(referer, '?') = 0;
            for (p = referer + strlen(referer) - 1; p > referer && *p != '/'; p--)
               *p = 0;
            if (strchr(referer, ' '))
               url_encode(referer, sizeof(referer));
         }

         /* extract browser */
         browser[0] = 0;
         if ((p = strstr(net_buffer, "User-Agent:")) != NULL) {
            p += 11;
            while (*p && *p == ' ')
               p++;
            strlcpy(browser, p, sizeof(browser));
            if (strchr(browser, '\r'))
               *strchr(browser, '\r') = 0;
         }

         /* extract "X-Forwarded-For:" */
         if ((p = strstr(net_buffer, "X-Forwarded-For:")) != NULL) {
            p += 16;
            while (*p && *p == ' ')
               p++;
            strlcpy(str, p, sizeof(str));
            if (strchr(str, '\r'))
               *strchr(str, '\r') = 0;
#ifdef _MSC_VER
            rem_addr.S_un.S_addr = inet_addr(str);
#else
            rem_addr.s_addr = inet_addr(str);
#endif
            phe = gethostbyaddr((char *) &rem_addr, 4, PF_INET);
            if (phe != NULL) {
               strcpy(remote_host[i_conn], phe->h_name);
               strcpy(rem_host, remote_host[i_conn]);
            }
         }

         memset(return_buffer, 0, return_buffer_size);
         strlen_retbuf = 0;
         if (strncmp(net_buffer, "GET", 3) != 0 && strncmp(net_buffer, "POST", 4) != 0)
            goto finished;
         return_length = 0;
         /* extract logbook */
         if (strchr(net_buffer, '/') == NULL || strchr(net_buffer, '\r') == NULL
             || strstr(net_buffer, "HTTP") == NULL) {
            /* invalid request, make valid */
            strcpy(net_buffer, "GET / HTTP/1.0\r\n\r\n");
         }

         p = strchr(net_buffer, '/') + 1;
         logbook[0] = 0;
         for (i = 0; *p && *p != '/' && *p != '?' && *p != ' '; i++)
            logbook[i] = *p++;
         logbook[i] = 0;
         strcpy(logbook_enc, logbook);
         url_decode(logbook);
         /* check for trailing '/' after logbook */
         if (strstr(net_buffer, "POST") == NULL) {      // fix for konqueror
            if (logbook[0] && *p == ' ') {
               if (!strstr(logbook, ".css") && !strstr(logbook, ".htm")
                   && !strstr(logbook, ".gif") && !strstr(logbook, ".jpg")) {
                  sprintf(str, "%s/", logbook_enc);
                  redirect(NULL, str);
                  goto redir;
               }
            }
         }

         /* check for trailing '/' after logbook/ID */
         if (logbook[0] && *p == '/' && *(p + 1) != ' ') {
            sprintf(url, "%s", logbook_enc);
            pd = url + strlen(url);
            while (*p && *p != ' ')
               *pd++ = *p++;
            *pd = 0;
            if (*(p - 1) == '/') {
               sprintf(str, "Invalid URL: %s", url);
               show_error(str);
               send(_sock, return_buffer, strlen_retbuf + 1, 0);
               keep_alive = 0;
               if (verbose) {
                  printf("==== Return ================================\n");
                  puts(return_buffer);
                  printf("\n\n");
               }
               goto finished;
            }
         }

         /* check if logbook exists */
         for (i = 0;; i++) {
            if (!enumgrp(i, str))
               break;
            if (equal_ustring(logbook, str))
               break;
         }

         if (strstr(logbook, ".gif") || strstr(logbook, ".jpg") ||
             strstr(logbook, ".jpg") || strstr(logbook, ".png")
             || strstr(logbook, ".htm")
             || strstr(logbook, ".css")) {
            /* check if file in resource directory */
            strlcpy(str, resource_dir, sizeof(str));
            strlcat(str, logbook, sizeof(str));
            if (exist_file(str))
               send_file_direct(str);
            else {
               /* else search file in themes directory */
               strlcpy(str, resource_dir, sizeof(str));
               strlcat(str, "themes", sizeof(str));
               strlcat(str, DIR_SEPARATOR_STR, sizeof(str));
               if (getcfg("global", "theme", theme))
                  strlcat(str, theme, sizeof(str));
               else
                  strlcat(str, "default", sizeof(str));
               strlcat(str, DIR_SEPARATOR_STR, sizeof(str));
               strlcat(str, logbook, sizeof(str));
               send_file_direct(str);
            }

            send(_sock, return_buffer, return_length, 0);
            if (verbose) {
               printf("==== Return ================================\n");
               puts(return_buffer);
               printf("\n\n");
            }

            goto finished;
         } else {
            if (!equal_ustring(logbook, str) && logbook[0]) {

               /* check for top group */
               sprintf(str, "Top group %s", logbook);
               if (!getcfg("global", str, list)) {

                  sprintf(str, "Error: logbook \"%s\" not defined in elogd.cfg", logbook);
                  show_error(str);
                  send(_sock, return_buffer, strlen(return_buffer), 0);
                  if (verbose) {
                     printf("==== Return ================================\n");
                     puts(return_buffer);
                     printf("\n\n");
                  }
                  goto finished;
               }
            }
         }

         /* if no logbook is given and only one logbook defined, use this one */
         if (!logbook[0]) {
            for (i = n = 0;; i++) {
               if (!enumgrp(i, str))
                  break;
               if (is_logbook(str))
                  n++;
            }

            if (n == 1) {
               strlcpy(logbook, str, sizeof(logbook));
               strlcpy(logbook_enc, logbook, sizeof(logbook_enc));
               url_encode(logbook_enc, sizeof(logbook_enc));
               strlcat(logbook_enc, "/", sizeof(logbook_enc));
               /* redirect to logbook, necessary to get optional cookies for that logbook */
               redirect(NULL, logbook_enc);
               send(_sock, return_buffer, strlen(return_buffer), 0);
               if (verbose) {
                  printf("==== Return ================================\n");
                  puts(return_buffer);
                  printf("\n\n");
               }
               goto finished;
            }
         }

         /*---- check "hosts deny" ----*/

         authorized = 1;
         if (getcfg(logbook, "Hosts deny", list)) {
            strcpy(rem_host_ip, (char *) inet_ntoa(rem_addr));
            n = strbreak(list, host_list, MAX_N_LIST);
            /* check if current connection matches anyone on the list */
            for (i = 0; i < n; i++) {
               if (equal_ustring(rem_host, host_list[i]) ||
                   equal_ustring(rem_host_ip, host_list[i])
                   || equal_ustring(host_list[i], "all")) {
                  if (verbose)
                     printf
                         ("Remote host \"%s\" matches \"%s\" in \"Hosts deny\". Access denied.\n",
                          equal_ustring(rem_host_ip,
                                        host_list[i]) ? rem_host_ip : rem_host,
                          host_list[i]);
                  authorized = 0;
                  break;
               }
               if (host_list[i][0] == '.') {
                  if (strlen(rem_host) > strlen(host_list[i]) &&
                      equal_ustring(host_list[i],
                                    rem_host + strlen(rem_host) - strlen(host_list[i]))) {
                     if (verbose)
                        printf
                            ("Remote host \"%s\" matches \"%s\" in \"Hosts deny\". Access denied.\n",
                             rem_host, host_list[i]);
                     authorized = 0;
                     break;
                  }
               }
               if (host_list[i][strlen(host_list[i]) - 1] == '.') {
                  strcpy(str, rem_host_ip);
                  if (strlen(str) > strlen(host_list[i]))
                     str[strlen(host_list[i])] = 0;
                  if (equal_ustring(host_list[i], str)) {
                     if (verbose)
                        printf
                            ("Remote host \"%s\" matches \"%s\" in \"Hosts deny\". Access denied.\n",
                             rem_host_ip, host_list[i]);
                     authorized = 0;
                     break;
                  }
               }
            }
         }

         /*---- check "hosts allow" ----*/

         if (getcfg(logbook, "Hosts allow", list)) {
            strcpy(rem_host_ip, (char *) inet_ntoa(acc_addr.sin_addr));
            n = strbreak(list, host_list, MAX_N_LIST);
            /* check if current connection matches anyone on the list */
            for (i = 0; i < n; i++) {
               if (equal_ustring(rem_host, host_list[i]) ||
                   equal_ustring(rem_host_ip, host_list[i])
                   || equal_ustring(host_list[i], "all")) {
                  if (verbose)
                     printf
                         ("Remote host \"%s\" matches \"%s\" in \"Hosts allow\". Access granted.\n",
                          equal_ustring(rem_host_ip,
                                        host_list[i]) ? rem_host_ip : rem_host,
                          host_list[i]);
                  authorized = 1;
                  break;
               }
               if (host_list[i][0] == '.') {
                  if (strlen(rem_host) > strlen(host_list[i]) &&
                      equal_ustring(host_list[i],
                                    rem_host + strlen(rem_host) - strlen(host_list[i]))) {
                     if (verbose)
                        printf
                            ("Remote host \"%s\" matches \"%s\" in \"Hosts allow\". Access granted.\n",
                             rem_host, host_list[i]);
                     authorized = 1;
                     break;
                  }
               }
               if (host_list[i][strlen(host_list[i]) - 1] == '.') {
                  strcpy(str, rem_host_ip);
                  if (strlen(str) > strlen(host_list[i]))
                     str[strlen(host_list[i])] = 0;
                  if (equal_ustring(host_list[i], str)) {
                     if (verbose)
                        printf
                            ("Remote host \"%s\" matches \"%s\" in \"Hosts allow\". Access granted.\n",
                             rem_host_ip, host_list[i]);
                     authorized = 1;
                     break;
                  }
               }
            }
         }

         if (!authorized) {
            keep_alive = 0;
            goto finished;
         }

         /* ask for password if configured */
         authorized = 1;
         if (getcfg(logbook, "Read Password", pwd)) {
            authorized = 0;
            /* decode authorization */
            if (strstr(net_buffer, "Authorization:")) {
               p = strstr(net_buffer, "Authorization:") + 14;
               if (strstr(p, "Basic")) {
                  p = strstr(p, "Basic") + 6;
                  while (*p == ' ')
                     p++;
                  i = 0;
                  while (*p && *p != ' ' && *p != '\r')
                     str[i++] = *p++;
                  str[i] = 0;
               }
               base64_decode(str, cl_pwd);
               if (strchr(cl_pwd, ':')) {
                  p = strchr(cl_pwd, ':') + 1;
                  do_crypt(p, str);
                  strcpy(cl_pwd, str);
                  /* check authorization */
                  if (strcmp(str, pwd) == 0)
                     authorized = 1;
               }
            }
         }

         /* check for Keep-alive */
         if (strstr(net_buffer, "Keep-Alive") != NULL && use_keepalive)
            keep_alive = TRUE;
         if (!authorized) {
            /* return request for authorization */
            rsprintf("HTTP/1.1 401 Authorization Required\r\n");
            rsprintf("Server: ELOG HTTP %s\r\n", VERSION);
            rsprintf("WWW-Authenticate: Basic realm=\"%s\"\r\n", logbook);
            rsprintf("Connection: close\r\n");
            rsprintf("Content-Type: text/html\r\n\r\n");
            rsprintf("<HTML><HEAD>\r\n");
            rsprintf("<TITLE>401 Authorization Required</TITLE>\r\n");
            rsprintf("</HEAD><BODY>\r\n");
            rsprintf("<H1>Authorization Required</H1>\r\n");
            rsprintf("This server could not verify that you\r\n");
            rsprintf("are authorized to access the document\r\n");
            rsprintf("requested. Either you supplied the wrong\r\n");
            rsprintf("credentials (e.g., bad password), or your\r\n");
            rsprintf("browser doesn't understand how to supply\r\n");
            rsprintf("the credentials required.<P>\r\n");
            rsprintf("</BODY></HTML>\r\n");
            keep_alive = FALSE;
         } else {
            if (strncmp(net_buffer, "GET", 3) == 0) {
               /* extract path and commands */
               *strchr(net_buffer, '\r') = 0;
               if (!strstr(net_buffer, "HTTP"))
                  goto finished;
               *(strstr(net_buffer, "HTTP") - 1) = 0;
               /* strip logbook from path */
               p = net_buffer + 5;
               for (i = 0; *p && *p != '/' && *p != '?'; p++);
               while (*p && *p == '/')
                  p++;
               /* decode command and return answer */
               decode_get(logbook, p);
            } else if (strncmp(net_buffer, "POST", 4) == 0) {
               if (verbose)
                  puts(net_buffer + header_length);
               /* get logbook from list (needed for attachment dir) */
               for (i = 0; lb_list[i].name[0]; i++)
                  if (equal_ustring(logbook, lb_list[i].name))
                     break;
               decode_post(&lb_list[i], net_buffer + header_length, boundary,
                           content_length);
            } else {
               net_buffer[50] = 0;
               sprintf(str, "Unknown request:<p>%s", net_buffer);
               show_error(str);
            }
         }

       redir:
         if (return_length != -1) {
            if (return_length == 0)
               return_length = strlen_retbuf;
            if (keep_alive
                && strstr(return_buffer, "Content-Length") == NULL
                || strstr(return_buffer, "Content-Length") > strstr(return_buffer,
                                                                    "\r\n\r\n")) {
               /*---- add content-length ----*/

               p = strstr(return_buffer, "\r\n\r\n");
               if (p != NULL) {
                  length = strlen(p + 4);
                  header_length = (int) (p - return_buffer);
                  memcpy(header_buffer, return_buffer, header_length);
                  sprintf(header_buffer + header_length,
                          "\r\nContent-Length: %d\r\n\r\n", length);
                  send(_sock, header_buffer, strlen(header_buffer), 0);
                  send(_sock, p + 4, length, 0);
                  if (verbose) {
                     printf("==== Return ================================\n");
                     puts(header_buffer);
                     puts(p + 2);
                     printf("\n");
                  }
               } else {
                  printf("Internal error, no valid header!\n");
                  keep_alive = 0;
               }
            } else {
               send(_sock, return_buffer, return_length, 0);
               if (verbose) {
                  printf("==== Return ================================\n");
                  puts(return_buffer);
                  printf("\n\n");
               }
            }
          finished:

            if (!keep_alive) {
               closesocket(_sock);
               ka_sock[i_conn] = 0;
#ifdef DEBUG_CONN
               printf("## close connection %d\n", i_conn);
#endif
            }
         }
      }
#ifdef OS_WINNT

      /* under windows, check if configuration changed (via stat()) once each access */
      check_config();

#else

      /* under unix, rely on "kill -HUP elogd" */
      if (_hup) {
         /* reload configuration */
         check_config();
         _hup = FALSE;
      }
#endif

      /* check for periodic tasks */
      check_cron();

   } while (!_abort);

   printf("Server aborted.\n");
}

/*------------------------------------------------------------------*/

void create_password(char *logbook, char *name, char *pwd)
{
   int fh, length, i;
   char *cfgbuffer, str[256], *p;

   fh = open(config_file, O_RDONLY);
   if (fh < 0) {
      /* create new file */
      fh = open(config_file, O_CREAT | O_WRONLY, 0640);
      if (fh < 0) {
         printf("Cannot create \"%s\".\n", config_file);
         return;
      }
      sprintf(str, "[%s]\n%s=%s\n", logbook, name, pwd);
      write(fh, str, strlen(str));
      close(fh);
      printf("File \"%s\" created with password in logbook \"%s\".\n", config_file,
             logbook);
      return;
   }

   /* read existing file and add password */
   length = lseek(fh, 0, SEEK_END);
   lseek(fh, 0, SEEK_SET);
   cfgbuffer = malloc(length + 1);
   if (cfgbuffer == NULL) {
      close(fh);
      return;
   }
   length = read(fh, cfgbuffer, length);
   cfgbuffer[length] = 0;
   close(fh);
   fh = open(config_file, O_TRUNC | O_WRONLY, 0640);
   sprintf(str, "[%s]", logbook);
   /* check if logbook exists already */
   if (strstr(cfgbuffer, str)) {
      p = strstr(cfgbuffer, str);
      /* search password in current logbook */
      do {
         while (*p && *p != '\n')
            p++;
         if (*p && *p == '\n')
            p++;
         if (strncmp(p, name, strlen(name)) == 0) {
            /* replace existing password */
            i = (int) (p - cfgbuffer);
            write(fh, cfgbuffer, i);
            sprintf(str, "%s=%s\n", name, pwd);
            write(fh, str, strlen(str));
            printf("Password replaced in logbook \"%s\".\n", logbook);
            while (*p && *p != '\n')
               p++;
            if (*p && *p == '\n')
               p++;
            /* write remainder of file */
            write(fh, p, strlen(p));
            free(cfgbuffer);
            close(fh);
            return;
         }

      } while (*p && *p != '[');
      if (!*p || *p == '[') {
         /* enter password into current logbook */
         p = strstr(cfgbuffer, str);
         while (*p && *p != '\n')
            p++;
         if (*p && *p == '\n')
            p++;
         i = (int) (p - cfgbuffer);
         write(fh, cfgbuffer, i);
         sprintf(str, "%s=%s\n", name, pwd);
         write(fh, str, strlen(str));
         printf("Password added to logbook \"%s\".\n", logbook);
         /* write remainder of file */
         write(fh, p, strlen(p));
         free(cfgbuffer);
         close(fh);
         return;
      }
   } else {                     /* write new logbook entry */

      write(fh, cfgbuffer, strlen(cfgbuffer));
      sprintf(str, "\n[%s]\n%s=%s\n\n", logbook, name, pwd);
      write(fh, str, strlen(str));
      printf("Password added to new logbook \"%s\".\n", logbook);
   }

   free(cfgbuffer);
   close(fh);
}

void cleanup(void)
{
#ifdef OS_UNIX
   char str[256];

   /* regain original uid */
   if (setegid(orig_gid) < 0 || seteuid(orig_uid) < 0)
      printf("Cannot restore original GID/UID.\n");
   if (pidfile[0]) {
      if (remove(pidfile) < 0) {
         sprintf(str, "Cannot remove pidfile \"%s\"\n", pidfile);
         perror(str);
      }
   }
#endif
}

/*------------------------------------------------------------------*/

int main(int argc, char *argv[])
{
   int i, fh, tcp_port_cl;
   int daemon = FALSE;
   char read_pwd[80], write_pwd[80], admin_pwd[80], str[256], logbook[256];
   time_t now;
   struct tm *tms;

#ifdef OS_UNIX
   /* save gid/uid to regain later */
   orig_gid = getegid();
   orig_uid = geteuid();
#endif
   /* register cleanup function */
   atexit(cleanup);
   tzset();
   read_pwd[0] = write_pwd[0] = admin_pwd[0] = logbook[0] = 0;
   logbook_dir[0] = resource_dir[0] = logbook_dir[0] = pidfile[0] = 0;
   tcp_port_cl = 0;
   /* default config file */
   strcpy(config_file, "elogd.cfg");
   /* evaluate predefined files and directories */
#ifdef CONFIG_FILE
   strlcpy(config_file, CONFIG_FILE, sizeof(config_file));
#endif
#ifdef RESOURCE_DIR
   strlcpy(resource_dir, RESOURCE_DIR, sizeof(resource_dir));
#endif
#ifdef LOGBOOK_DIR
   strlcpy(logbook_dir, LOGBOOK_DIR, sizeof(logbook_dir));
#endif
   /* look for config file in command line parameters */
   for (i = 1; i < argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == 'c')
         strcpy(config_file, argv[i + 1]);
   }

   /* check for configuration file */
   fh = open(config_file, O_RDONLY | O_BINARY);
   if (fh < 0) {
      printf("Configuration file \"%s\" not found.\n", config_file);
      exit(EXIT_FAILURE);
   }
   close(fh);
   /* evaluate directories fron config file */
   if (getcfg("global", "Resource Dir", str))
      strlcpy(resource_dir, str, sizeof(resource_dir));
   if (getcfg("global", "Logbook Dir", str))
      strlcpy(logbook_dir, str, sizeof(logbook_dir));
   use_keepalive = TRUE;
   /* parse command line parameters */
   for (i = 1; i < argc; i++) {
      if (argv[i][0] == '-' && argv[i][1] == 'D')
         daemon = TRUE;
      else if (argv[i][0] == '-' && argv[i][1] == 'v')
         verbose = TRUE;
      else if (argv[i][0] == '-' && argv[i][1] == 'k')
         use_keepalive = FALSE;
      else if (argv[i][0] == '-' && argv[i][1] == 'x')
         enable_execute = TRUE;
      else if (argv[i][1] == 't') {
         time(&now);
         tms = localtime(&now);
         printf("Actual date/time: %02d%02d%02d_%02d%02d%02d\n",
                tms->tm_year % 100, tms->tm_mon + 1, tms->tm_mday, tms->tm_hour,
                tms->tm_min, tms->tm_sec);
         exit(EXIT_SUCCESS);
      } else if (argv[i][0] == '-') {
         if (i + 1 >= argc || argv[i + 1][0] == '-')
            goto usage;
         if (argv[i][1] == 'p')
            tcp_port_cl = atoi(argv[++i]);
         else if (argv[i][1] == 'c')
            strcpy(config_file, argv[++i]);
         else if (argv[i][1] == 's')
            strcpy(resource_dir, argv[++i]);
         else if (argv[i][1] == 'd')
            strcpy(logbook_dir, argv[++i]);
         else if (argv[i][1] == 'r')
            strcpy(read_pwd, argv[++i]);
         else if (argv[i][1] == 'w')
            strcpy(write_pwd, argv[++i]);
         else if (argv[i][1] == 'a')
            strcpy(admin_pwd, argv[++i]);
         else if (argv[i][1] == 'l')
            strcpy(logbook, argv[++i]);
         else if (argv[i][1] == 'h')
            strlcpy(tcp_hostname, argv[++i], sizeof(tcp_hostname));
         else if (argv[i][1] == 'f')
            strlcpy(pidfile, argv[++i], sizeof(pidfile));
         else {
          usage:
            printf
                ("usage: %s [-p port] [-h hostname] [-D] [-c file] [-r pwd] [-w pwd] [-a pwd] [-l logbook] [-k] [-f file]\n\n",
                 argv[0]);
            printf("       -p <port> TCP/IP port\n");
            printf("       -h <hostname> TCP/IP hostname\n");
            printf("       -D become a daemon\n");
            printf("       -c <file> specify configuration file\n");
            printf("       -s <dir> specify resource directory (themes, icons, ...)\n");
            printf("       -d <dir> specify logbook root directory\n");
            printf("       -v debugging output\n");
            printf("       -r create/overwrite read password in config file\n");
            printf("       -w create/overwrite write password in config file\n");
            printf("       -a create/overwrite admin password in config file\n");
            printf("       -l <logbook> specify logbook for -r and -w commands\n\n");
            printf("       -k do not use keep-alive\n");
            printf("       -f path/filename for PID file\n");
            printf("       -x enable execution of shell commands\n\n");
            exit(EXIT_SUCCESS);
         }
      }
   }

   if ((read_pwd[0] || write_pwd[0] || admin_pwd[0]) && !logbook[0]) {
      printf("Must specify a lookbook via the -l parameter.\n");
      exit(EXIT_SUCCESS);
   }

   if (read_pwd[0]) {
      do_crypt(read_pwd, str);
      create_password(logbook, "Read Password", str);
      exit(EXIT_SUCCESS);
   }

   if (write_pwd[0]) {
      do_crypt(write_pwd, str);
      create_password(logbook, "Write Password", str);
      exit(EXIT_SUCCESS);
   }

   if (admin_pwd[0]) {
      do_crypt(admin_pwd, str);
      create_password(logbook, "Admin Password", str);
      exit(EXIT_SUCCESS);
   }

   /* extract resource directory from configuration file if not given */
   if (config_file[0] && strchr(config_file, DIR_SEPARATOR)
       && !resource_dir[0]) {
      strcpy(resource_dir, config_file);
      for (i = strlen(resource_dir) - 1; i > 0; i--) {
         if (resource_dir[i] == DIR_SEPARATOR)
            break;
         resource_dir[i] = 0;
      }
   }

   /* do the same for the logbook dir */
   if (config_file[0] && strchr(config_file, DIR_SEPARATOR)
       && !logbook_dir[0]) {
      strcpy(logbook_dir, config_file);
      for (i = strlen(logbook_dir) - 1; i > 0; i--) {
         if (logbook_dir[i] == DIR_SEPARATOR)
            break;
         logbook_dir[i] = 0;
      }
      strlcat(logbook_dir, "logbooks", sizeof(logbook_dir));
   }

   /* set default logbook dir if not given */
   if (!logbook_dir[0])
      strcpy(logbook_dir, "logbooks");
   if (resource_dir[0]
       && resource_dir[strlen(resource_dir) - 1] != DIR_SEPARATOR)
      strlcat(resource_dir, DIR_SEPARATOR_STR, sizeof(resource_dir));
   if (logbook_dir[0]
       && logbook_dir[strlen(logbook_dir) - 1] != DIR_SEPARATOR)
      strlcat(logbook_dir, DIR_SEPARATOR_STR, sizeof(logbook_dir));
   if (verbose) {
      printf("Config file  : %s\n", config_file);
      printf("Resource dir : %s\n", resource_dir[0] ? resource_dir : "current dir");
      printf("Logbook dir  : %s\n", logbook_dir[0] ? logbook_dir : "current dir");
   }

   /* get port from configuration file */
   if (tcp_port_cl != 0)
      tcp_port = tcp_port_cl;
   else {
      if (getcfg("global", "Port", str))
         tcp_port = atoi(str);
   }

   server_loop(tcp_port, daemon);
   exit(EXIT_SUCCESS);
}
