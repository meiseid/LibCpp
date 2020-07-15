#ifdef _USE_PGSQL
// PostgreSQL
//
#ifndef __LPgSQL_h__
#define __LPgSQL_h__

#include "libcpp.h"
#include <postgresql/libpq-fe.h>

class LPgSQL {
public:
	const char *mParam;
	int mStatus;
	char mMessage[512];
	PGconn *mConn;
	PGresult *mResult;
	int mTuples;

	LPgSQL(const char *param);
	virtual	~LPgSQL(void);
	bool connect(void);
	bool exec(const char *sql);
};

#endif //__LPgSQL_h__

#endif //_USE_PGSQL
