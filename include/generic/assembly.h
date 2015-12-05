#ifndef	_GENERIC_ASSEMBLY_H_
#define	_GENERIC_ASSEMBLY_H_

#ifndef	__ASSEMBLY__
#error "No need to #include <arch/assembly.h> here"
#endif


#ifndef	GLOBAL
#define	GLOBAL(name)		\
	.global name;		\
	name
#endif

#ifndef	LOCAL
#define	LOCAL(name)		\
	name
#endif

#define	ASM_SIZE(name)		\
	.size name, . - name

#ifndef	ASM_TYPE
#define	ASM_TYPE(type)		\
	@type
#endif

#ifndef	ENDFUN
#define	ENDFUN(name)		\
	.type name, ASM_TYPE(function);	\
	ASM_SIZE(name)
#endif

#endif
