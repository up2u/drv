#include <stdio.h>

typedef struct stu_s
{
    char name[10];
    int id;
}stu_t;

int main()
{
    char msg[10] = "woshi";

    printf("msg is %s\n", msg); // this can be output

    stu_t li = { // use prefix
        .name = "limao",
        .id = 23
    };
    printf("use struct 1: name = %s, id = %d\n", li.name, li.id); // can output

    stu_t fei = { // directly
        "feimao",
        56
    };
    printf("use struct 2: name = %s, id = %d\n", fei.name, fei.id);
// NOTE : this will error !
//    stu_t ma = { // use whole prefix
//        .name[10] = "mama", // array index in initializer exceeds array bounds
//        .id = 60
//    };
//    printf("use struct 3: name = %s, id = %d\n", ma.name, ma.id);

// now assign it a string
// then change it
    stu_t ba = {
        .name =  "baba",
        .id = 63
    };
    printf("use struct 3: name = %s, id = %d\n", ba.name, ba.id);
    printf("now change it \n");
    ba.name[0] = 'x';  // successful !
    printf("use struct 3: name = %s, id = %d\n", ba.name, ba.id);

    return 0;
}
