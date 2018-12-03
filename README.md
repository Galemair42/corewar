# corewar

Premier programmes a realiser :
assembleur capable de compiler un langage ASM personnalise, ce langage ASM permettant d'ecrire des "champions" qui seront
exucutes par le second programmes (la vm), ce programme sort donc un binaire qui represente un champion qui servira
d'input a la machine virtuelle.

Second programme a realiser :
petite machine virtuelle capable d'execute un set d'instruction specifique conçu pour faire s'affronter different champion,
les champions partagent une meme "zone memoire", ils peuvent donc se corrompre, ils sont place en memoire au tout debut à des
points d'entrés egaux en distance, ils disposeront chacun d'un processus au debut qui executera leurs code, leurs donnant la
possibilité de faire spawn d'autres processus et d'utiliser tout un pannel de techniques dans le but de battre ses adversaires.
