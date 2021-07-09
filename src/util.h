#ifndef UTIL_H
#define UTIL_H

#define ARRAY_SIZE(arr) sizeof(arr) / sizeof(arr[0])


#define __FILENAME__    (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define CHECK_ERROR(condition, ...) if(condition)												\
	{																							\
		printf(##__VA_ARGS__);																	\
		printf("\n\tAt: %s:%d\n\tFunc: %s\n", __FILENAME__, __LINE__, __FUNCSIG__);				\
		exit(1);																				\
	}

#endif // THEY SAID IT WOULD BE FUN THEY SAID
