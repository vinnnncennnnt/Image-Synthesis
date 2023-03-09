CXX=g++
CXXFLAGS=-Wall -g
LDFLAGS=

# XINCS = -I /usr/X11R6/include
XLIBS= -ltiff -L/usr/X11R6/lib -lX11
# les libs : -lX11 -ltiff

EXEC=tp testpermut
OBJECTS=main_tp.o image_4b.o matrix2d.o permuteur.o textureur.o x11display_code.o raccordeur_simple.o raccordeurRecursifNaif.o raccordeurRecursifNaifOptimise.o raccordeurIteratif.o 

usage:
	@echo "Cible possibles :"
	@echo " make tp"
	@echo " make testpermut"
	@echo " make all"

all: $(EXEC)

testpermut: permuteur.o main_testpermut.o
	$(CXX) $(LDFLAGS) -o testpermut $^ 

tp: $(OBJECTS)
	$(CXX) $(LDFLAGS) -o tp $^ $(XLIBS) 

image_4b.o: headers/image_4b.h
main_tp.o: headers/matrix2d.h headers/descripteur_tache.h headers/raccordeur.h headers/permuteur.h headers/raccordeur_simple.h 
matrix2d.o: headers/matrix2d.h
permuteur.o: headers/permuteur.h headers/tools.h
raccordeur_simple.o: headers/raccordeur_simple.h headers/raccordeur.h headers/matrix2d.h
textureur.o: headers/textureur.h headers/matrix2d.h headers/descripteur_tache.h headers/raccordeur.h headers/permuteur.h
x11display_code.o: headers/x11display_code.h
raccordeurRecursifNaif.o : headers/raccordeurRecursifNaif.hpp
raccordeurRecursifNaifOptimise.o : headers/raccordeurRecursifNaifOptimise.hpp
raccordeurIteratif.o : headers/raccordeurIteratif.hpp

%.o: source/%.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS) 

clean: 
	rm -f $(EXEC) *.o

# Differents outils (peut important pour la compréhension)

#lib:
#	g++ -c -o image_4b.o image_4b.cpp
#	g++ -c -o x11display_code.o x11display_code.cpp
#	ar -rcvs libtpalgo.a image_4b.o x11display_code.o

tar:
	@echo "NOT IMPLEMENTED"
#tar -cf ../tpalgo.tar {image_4b,x11display_code}.{hh,cc} \
		textureur.{hh,cc} main_tp.cpp \
		matint2.{hh,cc} Makefile *.tif

scp:
	@echo "NOT IMPLEMENTED"
#scp src2007.tar lux@ensibm:/perms/lux/TPALGO/src.tar

