// 静的ツール
//
#ifndef __G_h__
#define __G_h__
#include "libcpp.h"

class G
{
public:
	static int sizeFile( const char *path,time_t *mtime );
	static void urlDecode( std::string &src,std::string &dst );
	static void urlEncode( std::string &src,std::string &dst );
	static void xmlDecode( std::string &src,std::string &dst );
	static void xmlEncode( std::string &src,std::string &dst );
	static void replace( std::string &str,std::string from,std::string to );
	static int split( const char *src,char key,std::vector<std::string> &dst );
	static std::string readTextFile( const char *path );
	static void readConfigFile( std::string path,std::vector<SParam> &params );
	static void readSinglePart( char *mem,size_t len,char sep,std::vector<SParam> &params );
	static char* paramText( const char *key,const std::vector<SParam> &params );
	static std::string clockText( std::string label );
	static void getDateText( const struct tm *src,char *dst,size_t len );
	static int addText( std::string &str,const char *fmt, ... );
	static int addBigText( std::string &str,const char *fmt, ... );
	static void costText( int cost_num,char *cost_str );
	static std::string trimingText( const std::string &src );
	static void headerText( const char *src,char *dst,int count );
	static char* hankakuToZenkaku( const char *src,char *dst );
	static char* zenkakuToHankaku( const char *src,char *dst );
	static unsigned char* base64Encode( const unsigned char *str,int length,int *ret_length );
};

#endif //__G_h__
