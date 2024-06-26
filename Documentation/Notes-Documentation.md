Conférences 42sh 2019 (n.b.: Epitech) - Architecture d'un shell ([YouTube](https://www.youtube.com/watch?v=oIFRiwFRSRY&t=745s))
- What matters is to be able to execute a command => if's, etc. come after
- Read [Shell Command Language manual](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
 	=> remark by Cmegret: we probably won't read too much in detail in the beginning
- Toujours avoir quelque chose de fonctionnel à montrer (vs "dans 2 semaines on aura qqch")
- Ne pas faire en bloc: parsing, ensuite expanding, ensuite execution; plutôt faire parsing basique de commandes, puis rajouter de la complexité. Par exemple, être capable de parser et exécuter une seule commande, puis rajouter des if, etc.
- Syntax abstraite vs concrète, arbre de parsing:
pas faire un arbre de parsing complet avant de coder => plutôt, partir du truc "inratable" => parser des commandes simples et faire `fork exec`
- Tester les choses séparément, au fur et à mesure
- Subshell: attention à l'historique
- Ce qui est compliqué c'est pas d'exécuter une commande, mais les variables et les substitutions
- Posix (57:00): "un shell POSIX ça n'existe pas; ce qui existe c'est un script Shell qui se sert que du sous-ensemble Posix des features du shell" ). Il y a quelques comportements que Bash ne respecte pas concernant Posix, notamment ordre des pipes et valeurs retour en cas d'un fail. => quelle valeur retour quand j'ai plusieurs commandes dans mon pipe ? `bash --posix` change le comportement du pipe et tous les comportements qui changent par rapport à POSIX, mais ne désactive pas toutes les extensions du bash, e.g. `if [[ ]]`
- Cas d'erreur: le shell est un langage de m..... des comportements sont indéfinis ou mal définis dans la spec (SCL)
=> ne pas se casser la tête et suivre le comportement de Bash; le but est de faire un shell qui marche, pas suivre Bash dans les comportements les plus stupides
- Allez lire des bouts de shell, ça vaut le coup; pas Bash, plutôt des choses comme [ksh](https://github.com/openbsd/src/tree/master/bin/ksh) => "au fait, toi tu fais comment ?" e.g. quels sont les appels systèmes quand je fais tel ou tel truc (avec `strace`). Attention aussi aux optimisations qui sont faites pour éviter de fork trop de fois (il y a des commandes implémentées en builtin, etc.)
- **Faire des tests dès le début : créer des scripts shells, lancer avec un shell quelconque, vérifier si ça marche pareil
=> à chaque fois, quand on rajoute une feature, faire un test qui va avec; ça doit devenir un réflexe: "je veux que tel script marche, j'écris mon script, j'écris le shell" Permet de voir en continu si on a cassé quelque chose. Si on a le moindre bug, mettre le script dans les tests avant de faire quoi que ce soit**
=> faire du [test-driven development](https://en.wikipedia.org/wiki/Test-driven_development) => tests écrits avant le code, code écrit pour satisfaire les tests

Notions to explore:
- Abstract Syntax tree
- Here-docs
- [Process image](https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_process_image.htm)
- Job control ?

EnthusiastiCon - Stefanie Schirmer “OMG building a shell in 10 minutes” [YouTube](https://www.youtube.com/watch?v=k6TTj4C0LF0)
- Privileged space to interact with the kernel
- Very simplified shell:
	- Prompt to input things
	- Parse user input
	- Run builtin commands for job control
	- Run other system commands and show their output
- Execvp replaces the current process with a new process image

## Concepts
### Shell builtin 
`man builtin`: 
> Shell builtin commands are commands that can be executed within the running shell's process.
> If a command specified to the shell contains a slash ‘/’, the shell will not execute a builtin command, even if the last component of the specified command matches the name of a builtin command.  Thus, while specifying “echo” causes a builtin command to be executed under shells that support the echo builtin command, specifying “/bin/echo” or “./echo” does not.
> Consult a shell's manual page for details on the operation of its builtin commands.
=> `man bash` > search "SHELL BUILTIN COMMANDS"

=> Note: not clear what to do with builtins (copy them from bash? use builtins from the computer ?)

- [Shell builtin – Wikipedia](https://en.wikipedia.org/wiki/Shell_builtin)

### Here documents
- [Here documents - TLDP](https://tldp.org/LDP/abs/html/here-docs.html)
- [Heredocs - a deep dive](https://medium.com/@oduwoledare/heredoc-a-deep-dive-23c82992e522)

### EOF
- [EOF characters – Wikipedia](https://en.wikipedia.org/wiki/End-of-file#EOF_character)
- [EOF – Baeldung](https://www.baeldung.com/linux/eof)

## Minishell projects
- [Minishell Structure - Toni Schmitt - Github](https://github.com/toni-schmitt/minishell#lexer)
- [Conférences 42SH Redirection et Pipe  - 2019](https://www.youtube.com/watch?v=ceNaZzEoUhk)

## Shells
- [Shell Command Language manual](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html)
- [Bash5.2 manual](https://www.man7.org/linux/man-pages/man1/bash.1.html)
- [ksh source code](https://github.com/openbsd/src/blob/master/bin/ksh/exec.c)
- [Bash git repository](https://git.savannah.gnu.org/cgit/bash.git/tree/doc/README): Documentation is useful, has schemas etc. (according to tfrily)

## Git & Github
- [https://www.youtube.com/live/N4GAmMHnd20?si=KNtmaPRX4fybOGDc](Git avancé (50min))
- [Git bisect plugin](https://artspb.me/posts/getting-started-with-git-bisect-run-plugin/)
- [Conventional commits](https://www.conventionalcommits.org/en/v1.0.0/)

## Other
- [Pipex with bonus (heredocs)](https://github.com/madebypixel02/pipex?tab=readme-ov-file#here-document)
- [ExplainShell.com](https://explainshell.com/) (decomposes and explains shell commands)
