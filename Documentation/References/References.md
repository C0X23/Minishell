# Minishell references
## Shells
- [Shell Command Language manual - 2018 version (POSIX Shell)](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html) => check 2018 and not 2004 version !
- [Shell Command Language manual - 2024 version (POSIX Shell)](https://pubs.opengroup.org/onlinepubs/9799919799/) => last version (August)
- [Shell Command Language manual - PDF version (1994) (POSIX Shell)](https://pubs.opengroup.org/onlinepubs/009656399/toc.pdf) (n.b.: more readable)
- [Bash Reference Manual (v5.2)](https://www.gnu.org/software/bash/manual/bash.html)
- [`man Bash`(v5.2)](https://www.man7.org/linux/man-pages/man1/bash.1.html)
- [POSIX.1-2017 standard definitions](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap03.html)
- [The Bourne-Again Shell - The Architecture of Open Source Applications (Volume 1) - Chet Ramey](https://aosabook.org/en/v1/bash.html)
- [ksh source code](https://github.com/openbsd/src/blob/master/bin/ksh/exec.c)
- [Bash git repository](https://git.savannah.gnu.org/cgit/bash.git/tree/doc/README): Documentation is useful, has schemas etc. (according to tfrily)
- [Advanced Bash-Scripting Guide - TLDP](https://tldp.org/LDP/abs/html/)

## Minishell projects
- [EnthusiastiCon - Stefanie Schirmer “OMG building a shell in 10 minutes”](https://www.youtube.com/watch?v=k6TTj4C0LF0)
- [Conférences 42SH Redirection et Pipe  - 2019](https://www.youtube.com/watch?v=ceNaZzEoUhk)
- [Minishell Structure - Toni Schmitt - Github](https://github.com/toni-schmitt/minishell#lexer)

## Syntax and parsing
- [CSE12 UCSD - Abstract Syntax Trees](https://cseweb.ucsd.edu/~kube/cls/12.s13/Lectures/lec16/lec16.pdf)

## Testing
- [Conférences 42sh 2019 - Python & Testsuite fonctionnelle](https://www.youtube.com/watch?v=1CoFy6eM7_I&list=PLo31Bhg3nNkZHhqAjlwo5tNOa-FEXKnEe&index=6)

## Functions
### Builtins
- see `man bash`
- [Builtins - Bash Reference Manual (v5.2)](https://www.gnu.org/software/bash/manual/bash.html#Shell-Builtin-Commands)
- [Shell builtin – Wikipedia](https://en.wikipedia.org/wiki/Shell_builtin)

### Readline
- [The GNU Readline Library](https://www.gnu.org/software/readline/)

### File handling
#### Open
- [Using open to create a file in C - StackOverflow](https://stackoverflow.com/questions/28466715/using-open-to-create-a-file-in-c)

## Processes
- [Process image](https://www.tutorialspoint.com/inter_process_communication/inter_process_communication_process_image.htm)

## Variables
### Environment variables
- [Environmental variables - Open group specification](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap08.html)

- [What is pathname expansion](https://bash.cyberciti.biz/guide/Path_name_expansion)

## Signals
- [Bash reference manual - Signals](https://www.gnu.org/software/bash/manual/html_node/Signals.html)
- [Shell Command Language - Signals and Error handling](https://pubs.opengroup.org/onlinepubs/009695399/utilities/xcu_chap02.html#tag_02_11)
- [CTRL + D in a terminal - Quora](https://www.quora.com/What-is-Ctrl-D-in-a-terminal)
- [Signals - Learning the Korn Shell](https://docstore.mik.ua/orelly/unix2.1/ksh/ch08_03.htm)

## Redirections and pipes
- [Unix for the Bootcamp Grad: Part 1. Redirection and Pipelines - Kerry Sheldon](https://medium.com/@KerrySheldon/unix-for-the-bootcamp-grad-part-1-redirection-and-pipelines-470a7f6609c8)

- [Bash reference manual - Redirections](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Redirections)

- [exercises to understand redirections in bash - Google Search](https://www.google.com/search?client=firefox-b-d&q=exercises+to+understand+redirections+in+bash)

- [Pipes and Redirects - Master the Bash Shell](https://www.educative.io/courses/master-the-bash-shell/pipes-and-redirects)

- [zsh: understanding sequence of redirections and pipe with pointers - Unix & Linux Stack Exchange](https://unix.stackexchange.com/questions/673145/zsh-understanding-sequence-of-redirections-and-pipe-with-pointers)

- [Bash 101 Reference & Exercises](https://codingnomads.com/bash-101-reference-and-exercises)

- [How can you redirect the output of a command to a file in Bash scripting? - EITCA Academy](https://eitca.org/cybersecurity/eitc-is-lsa-linux-system-administration/bash-scripting/bash-basics/examination-review-bash-basics/how-can-you-redirect-the-output-of-a-command-to-a-file-in-bash-scripting/)

- [Shell, I/O redirections, and filters](https://musaoyiza.hashnode.dev/shell-io-redirections-and-filters)

- [Five ways to use redirect operators in Bash | Enable Sysadmin](https://www.redhat.com/sysadmin/redirect-operators-bash)

- [Learn Piping and Redirection - Linux Tutorial](https://ryanstutorials.net/linuxtutorial/piping.php)

- [Working with pipes on the Linux command line | Enable Sysadmin](https://www.redhat.com/sysadmin/pipes-command-line-linux)


### Here documents
- [Bash reference manual - Here Documents](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Here-Documents)
- [Here documents - TLDP](https://tldp.org/LDP/abs/html/here-docs.html)
- [Heredocs - a deep dive](https://medium.com/@oduwoledare/heredoc-a-deep-dive-23c82992e522)

## EOF
- [EOF characters – Wikipedia](https://en.wikipedia.org/wiki/End-of-file#EOF_character)
- [EOF – Baeldung](https://www.baeldung.com/linux/eof)

## Parsing
### Parsing concepts
- https://en.wikipedia.org/wiki/Abstract_syntax_tree / https://fr.wikipedia.org/wiki/Arbre_de_la_syntaxe_abstraite
- https://en.wikipedia.org/wiki/Parse_tree / https://fr.wikipedia.org/wiki/Arbre_syntaxique
- https://cs.stackexchange.com/questions/54814/different-between-left-most-and-right-most-derivation
- Parsing Techniques – Grune & Jacobs (2008)
### Types of parsers
- https://www.geeksforgeeks.org/types-of-parsers-in-compiler-design/
- [LL parser](https://en.wikipedia.org/wiki/LL_parser)
- [LR parser](https://www.geeksforgeeks.org/lr-parser)

## Execution
- [Bash reference manual - Executing commands](https://www.gnu.org/savannah-checkouts/gnu/bash/manual/bash.html#Executing-Commands)

## Tools
### Git & Github
- [Git avancé (50min) - 42sh](https://www.youtube.com/live/N4GAmMHnd20?si=KNtmaPRX4fybOGDc)
- [Git bisect plugin](https://artspb.me/posts/getting-started-with-git-bisect-run-plugin/)
- [Conventional commits](https://www.conventionalcommits.org/en/v1.0.0/)

## Diagrams
- https://guides.visual-paradigm.com/understanding-activity-diagrams-in-uml-a-comprehensive-guide/
- https://www.geeksforgeeks.org/unified-modeling-language-uml-activity-diagrams/?ref=lbp
- https://www.lucidchart.com/pages/uml-activity-diagram

## Other
- [Pipex with bonus (heredocs)](https://github.com/madebypixel02/pipex?tab=readme-ov-file#here-document)
- [ExplainShell.com](https://explainshell.com/) (decomposes and explains shell commands)\
- [The Meaning of IFS (Internal Field Separator) in Bash Scripting - Baeldung](https://www.baeldung.com/linux/ifs-shell-variable)
