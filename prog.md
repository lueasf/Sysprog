On utilise la lib *unistd.h* pour les appels systemes.

# PS
ps -ef
PID : Processus ID
PPID : Parent Processus ID
UID : User ID
C : facteur de priorité

action :
```bash ./pid & ```\\
ps -ef pour voir que le processus lancé dans le terminal,
a pour parent zsh.

# FORK
Un processus peut créer un autre processus.
On peut faire ça dans un programme C avec la fonction fork().
Quand on lance le programme, on voit avec ps que
zsh à lancé le programme et que le programme a lancé un autre processus.
Le programme a été dupliqué.

Faire la distinction entre le processus père et le processus fils :
fork() renvoie pid_t qui est un entier signé (-1, 0 ou n).
-1 : erreur
0 : processus fils
n : processus père et n est le pid du fils.
On voit que les processus ne partagent pas les variables.

On peut lancer plusieurs fork dans un programme.
Si on lance 2 dans le prog1, le fils 1 (du premier fork), va lancer son fils,
qui sera le petit fils du père. Le père va aussi lancer un autre fils.
Avec 2 fork, on a 4 processus. 
On conjecture n fork donne 2^n processus.

# WAIT
Ne savant pas lequel se termine avant lequel, on met
en place un mécanisme de synchronisation avec wait().

# WAITPID
On peut attendre un processus en particulier avec waitpid().