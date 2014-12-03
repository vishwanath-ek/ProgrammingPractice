#include <stdio.h>

typedef union {
    float lemon;
    int lemon_pieces;
} lemon_lime;

typedef struct {
    float tequila;
    float cointreau;
    lemon_lime citrus;
} margarita;

int main(){
    margarita m = {230.0, .cointreau = 112.123, .citrus.lemon = 2};
    printf("%2.1f tequila, %2.1f cointreau & %2.1f juice\n", m.tequila, m.cointreau, m.citrus.lemon);
    // Now if i type m = {230,112.23,{1}} itl be an error as compiler will feel its an array
    // and not a struct as margarita m = something implies declaraing its a struct in the same line.
    margarita n = {1,2.1,{2.2}};
    printf("%2.1f tequila, %2.1f cointreau & %2.1f juice\n", n.tequila, n.cointreau, n.citrus.lemon);
    margarita o = {1,2.1,{.lemon_pieces = 3}};
    printf("%2.1f tequila, %2.1f cointreau & %2d juice\n", o.tequila, o.cointreau, o.citrus.lemon_pieces);
 
    return 0;
}
