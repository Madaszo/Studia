#include <stdio.h>
int main ( void ){
float e = 2.718281828;
printf ("--------------------------------------------\n");
printf ("zmiennoprzecinkowe\n");
printf ("--------------------------------------------\n\n");
printf("  %%f    |%f\n",e);
printf("  %%.0f  |%.0f\n",e);
printf("  %%.0f. |%.0f.\n",e);
printf("  %%.1f  |%.1f\n",e);
printf("  %%.2f  |%.2f\n",e);
printf("  %%.6f  |%.6f\n",e);
printf("  %%.7f  |%.7f\n",e);
printf(" \n");
printf("  %%5.0f  |%5.0f\n",e);
printf("  %%5.1f  |%5.1f\n",e);
printf("  %%5.2f  |%5.2f\n",e);
printf("  %%5.7f  |%5.7f\n",e);
printf("  %%5.9f  |%5.9f\n",e);

printf ("--------------------------------------------\n");
printf ("calkowite\n");
printf ("--------------------------------------------\n\n");

printf("  %%3d  |%3d\n",12);
printf("  %%3d  |%3d\n",-12);
printf("  %%3d  |%3d\n",12564);
printf(" \n");
printf("  %%-5d  |%-5d\n",12);
printf("  %%-5d  |%-5d\n",-12);
printf(" \n");
printf("  %%05d  |%05d\n",12);
printf("  %%05d  |%05d\n",-12);
printf("  %%05d  |%05d\n",1287657);
printf(" \n");
printf("  %%5d  |%5d\n",12);
printf("  %%+5d  |%+5d\n",12);
printf("  %%+5d  |%+5d\n",-12);
printf(" \n");
printf("  %%+-5d  |%+-5d\n",12);
printf("  %%+-5d  |%+-5d\n",-12);
printf("  %% -5d  |% -5d\n",12);
printf("  %% -5d  |% -5d\n",-12);
printf(" \n");
printf("  %% 05d  |% 05d\n",12);
printf("  %% 05d  |% 05d\n",-12);
printf("  %% 05d  |% 05d\n",1235465);
printf("  %% 05d  |% 05d\n",-126578);
printf(" \n");
printf("  %%+05d  |%+05d\n",12);
printf("  %%+05d  |%+05d\n",-12);
printf("  %%+05d  |%+05d\n",1235465);
printf("  %%+05d  |%+05d\n",-126578);




return 0;
}
