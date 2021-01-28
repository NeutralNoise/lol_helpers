//Bradley Macdonald
//2020
#ifndef BYTE_SWAP_H_INCLUDED
#define BYTE_SWAP_H_INCLUDED

//NOTE This code was taken from the MUSL libc prject. http://musl.libc.org/
inline unsigned short bswap16(unsigned short v) {
    return v<<8 | v>>8;
}

inline unsigned int bswap32(unsigned int v) {
    return v>>24 | v>>8&0xff00 | v<<8&0xff0000 | v<<24;
}

inline unsigned short htons(unsigned short v) {
    union { int i; char c; } u = { 1 };
    return u.c ? bswap16(v) : v;
}

inline unsigned int htonl(unsigned int v) {
    union { int i; char c; } u = { 1 };
    return u.c ? bswap32(v) : v;
}

inline unsigned short ntohs(unsigned short v)
{
	union { int i; char c; } u = { 1 };
	return u.c ? bswap16(v) : v;
}

inline unsigned int ntohl(unsigned int v)
{
	union { int i; char c; } u = { 1 };
	return u.c ? bswap32(v) : v;
}

#endif //BYTE_SWAP_H_INCLUDED
