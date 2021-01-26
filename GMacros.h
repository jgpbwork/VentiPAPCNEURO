#ifndef GMACROS_H
#define GMACROS_H

#if __cplusplus >= 20113L //c++11 support
#define COMPILER_NULLPTR
#define COMPILER_DELETE_MEMBERS
#endif

#ifdef COMPILER_NULLPTR
#define G_NULLPTR nullptr
#else
#define G_NULLPTR NULL
#endif

#ifdef COMPILER_DELETE_MEMBERS
#define DECLARE_DELETE = delete
#else
#define DECLARE_DELETE
#endif

#define DECLARE_UNUSED(x) ((void) (x))

#define DISABLE_COPY(Class) \
    Class(const Class &) DECLARE_DELETE; \
    Class &operator=(const Class &) DECLARE_DELETE


//Test Pull from two repositories

#define Q_WAIT_FOREVER -1

#endif // GMACROS_H
