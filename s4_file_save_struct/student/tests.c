// CTester template

#include <stdlib.h>
#include "student_code.h"
#include "CTester/CTester.h"

point_t* gen_struct(int size){
    point_t *tab = malloc(size*sizeof(point_t));
    if (tab == NULL)
        return (point_t*)NULL;
    for (int i = 0; i < size; i++){
        tab[i].x = i+i;
        tab[i].y = i+i+i;
        tab[i].z = i+i*i;
    }
    return tab;
}

/*
 * Test with open fail
 */
void test() {
    set_test_metadata("q1", _("Test fail open"), 1);
    int size = 5;
    int ret = 0;
    point_t* tab = gen_struct(size);

    SANDBOX_BEGIN;
    ret = save(tab, size, "file.txt");
    SANDBOX_END;
    
    free(tab);
    tab = NULL;
    
    //Regenerate the struct in case student modified it
    tab = gen_struct(size);
    int fd = open("file.txt",O_RDONLY); 
    if(fd == -1) 
        CU_FAIL("Can not initialize test suite");

    point_t s;
    for(int i = 0; i < size; i++){
        read(fd, (void *) &s, sizeof(point_t));
    }
    printf("%d %d %d", s.x, s.y, s.z);
    close(fd);
    if (ret != -1){
        push_info_msg(_("bla"));
        CU_FAIL();
    }
}



int main(int argc,char** argv){
    BAN_FUNCS(system);
    RUN(test);
}
