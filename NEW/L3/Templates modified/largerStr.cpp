char * s1="abcd", * s2="efgh";
char * s3=larger(s1,s2); //compiler generates larger(const
		//char *&, const char *&); and
		//resolves the call
