// CGIプログラムクラスes
//
#ifndef __LCgi_h__
#define __LCgi_h__
#include "libcpp.h"

class LCgi
{
public:
	std::string mLogPath;
	std::string mLogStr;

	std::vector<SParam> mConfig;
	std::vector<SParam> mCgi;
	std::vector<SParam> mCookie;

	struct tm mDate;
	time_t mTime;
	char* mDateStr;

	std::string mClientIp;

	std::string mOutHead;
	std::string mOutBody;

	LCgi( int argc,char **argv );
	LCgi( void );
	virtual	~LCgi( void );
	virtual void run( void );
	virtual void finish( void );
	void readCgiParams( void );
	void readCookieParams( void );
};

#endif //__LCgi_h__
