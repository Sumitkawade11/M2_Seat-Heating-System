#include "activity_1.h"
#include "activity_2.h"
#include "activity_3.h"
#include "activity_4.h"
volatile uint16_t digital_value;
int main(void)
{
   while(1)
   {
   activity_1();
   digital_value = activity_2();
   activity_3(digital_value);
   activity_4(digital_value);
   }
   return 0;
}
