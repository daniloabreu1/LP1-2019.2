#include <stdio.h>
union pontos{
    int a;
    float b;
};

main(){
    union pontos u={2};
    printf("%d\n",u.a);
    u.b=4.5;
    printf("%f\n",u.b);
    printf("%d\n",u.a);
    u.a=786;
    printf("%d\n",u.a);
}
