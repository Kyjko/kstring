#include "kstring.h"

int main(int argc, char** argv) {

    String* mystr = create_string("hello world!");
    print(mystr);
    push(mystr, " WOW");
    print(mystr);

    destroy(mystr);

    return 0;
}
