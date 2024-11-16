# Si tu déplaces ce projet, tu peux changer ce répertoire
# pour qu'il corresponde à celui de ton installation GBDK
ifndef GBDK_HOME
	GBDK_HOME = ../
endif

# LCC est l'outil de compilation utilisé par GBDK
LCC = $(GBDK_HOME)bin/lcc

# Nom du fichier de sortie
BINS = theShow.gb

# Fichiers sources à compiler
SRC = main.c scene1.c logo.c dial.c chap1.c eric.c

# Activer les options de debug si nécessaire
# GBDK_DEBUG = ON
ifdef GBDK_DEBUG
	LCCFLAGS += -debug -v
endif

# Règle par défaut pour compiler le fichier GB
all: $(BINS)

# Compile et lie les fichiers sources
$(BINS): $(SRC)
	$(LCC) $(LCCFLAGS) -o $(BINS) $(SRC)

# Nettoyer les fichiers générés
clean:
	rm -f *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi *.rst
