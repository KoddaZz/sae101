prog = programme

QQ += $(prog)/main.c\
	$(prog)/etudiant.c\
	$(prog)/responsable.c\
	$(prog)/jury.c\
	$(prog)/fonctionsGlobales.c


sae101.exe : $(QQ)
	gcc -Wall $(QQ) -o sae101.exe

clean :
	rm sae101