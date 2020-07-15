#ifdef _USE_MYSQL
// MySQL
//
#ifndef __LMySQL_h__
#define __LMySQL_h__

#include "libcpp.h"
#include <mysql/mysql.h>

#define dMaxDbConn 4 //同時にコネクション張れるハンドル数

class LMySQL
{
public:
	std::string &mLogStr;
	char *mDBHost;
	char *mDBUser;
	char *mDBPass;
	char *mDBName;
	int mDBPort;

	MYSQL *mDB[dMaxDbConn]; 

	LMySQL( std::string &logstr );
	virtual	~LMySQL( void );

	bool connectDB( int db_index );
	void disconnectDB( int db_index );
	MYSQL_RES* readDB( int db_index,std::string query );
	bool writeDB( int db_index,std::string query );
	int countDB( int db_index,std::string query );
	const char* errorDB( int db_index );
	char* escapeDB( int db_index,const char *src );
};

#endif //__LMySQL_h__

#endif //_USE_MYSQL
