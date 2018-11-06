FlAGS = -g
JC = javac
EXECUTE = java


.SUFFIXES: .java .class

.java.class:
	$(JC) $(FLAGS) $*.java


CLASS = \
	Demineur.java\
	ControlerClique.java\
	ControlerFenetre.java\
	ControlerSouris.java \
	Fenetre.java \
	Jeu.java \
	JeuRun.java \
	Menu.java\

default: class

class: $(CLASS:.java=.class)

test:
	$(EXECUTE) Demineur

clean:
	$(RM) *.class
