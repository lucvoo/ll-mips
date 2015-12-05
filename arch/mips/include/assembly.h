#ifndef	_ARCH_ASSEMBLY_H_
#define	_ARCH_ASSEMBLY_H_


#define	ENTRY(name)		\
	.type	name, @function;\
	.ent	name;		\
name:


#define	ENDFUN(name)		\
	.end	name;		\
	.size	name, .-name


#endif
