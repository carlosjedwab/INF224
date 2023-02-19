##########################################
#
#  Exemple de Makefile
#  Carlos Jedwb - Telecom ParisTech 2023
#  INF224 - TP Java/Swing - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme (doit correspondre au fichier qui contient main())
#
PROG = MainWindow

#
# Fichiers sources .java
#
SOURCES = MainWindow.java  Client.java ButtonAction.java

#
# Compilateur Java
#
JC = javac

#
# Options du compilateur Java
#
JFLAGS = -g


##########################################
#
# Regles de construction/destruction des .class et de l'executable
#
 
all: classes

run: all
	java ${PROG}

classes: $(SOURCES:.java=.class)

clean:
	-@$(RM) *.class 1>/dev/null 2>&1
  
tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}


###########################################
#
# Regles implicites
#

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java


