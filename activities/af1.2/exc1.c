#include <stdio.h>

typedef struct {
    float x, y;
} ponto_t;

int main(void){
    ponto_t q = {23.0, 27.0};
    ponto_t* p = &q;

    // q->x++;
    q.x = q.y = p->x *= 2;
    // q.x = p
    // p->++x;
}