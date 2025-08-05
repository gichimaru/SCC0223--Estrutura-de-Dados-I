#include <stdio.h>
#include "jogo.h"
#include "catalogo.h"

int main() {
    CATALOGO *catalogo;
    catalogo = criar_catalogo();
    
    ler_jogos(catalogo);
    pesquisar(catalogo);
    apagar_catalogo(catalogo);

    return(0);
}