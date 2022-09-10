#include <cstdlib>
// if ANYTHING is asked to be defined specifically, only define those
// else, define everything

#ifndef RSDSTRING
   #ifndef RSDVECTOR
      #ifndef RSDARRAY
         #ifndef RSDIO
            #define RSDSTRING 1
            #define RSDVECTOR 1
            #define RSDARRAY 1
            #define RSDIO 1
         #endif
      #endif
   #endif
#endif


namespace RSD{

struct linkedList{
   linkedList* next=NULL;
   linkedList* prev=NULL;
   void* data;
};

#ifdef RSDSTRING
#include "include/string.hpp"
#endif
#ifdef RSDSTRING
#include "include/vector.hpp"
#endif
#ifdef RSDSTRING
#include "include/array.hpp"
#endif
#ifdef RSDSTRING
#include "include/io.hpp"
#endif
}
