#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

main()
{
   PrimeSeq s;
   long p;
   p = s.next();
   while (p <= 2000) {
      cout << p << "\n";
      p = s.next();
   }
}