## Markdown extension (e.g. md, markdown, mdown).
MEXT = md

## Markdown Template
TEMP-PWD =/home/corsi/Dropbox/Insper/Markdown
TEMP-TEXT = $(TEMP-PWD)/InsperTemplate.tex
TEMP-SLIDE = $(TEMP-PWD)/InsperTemplateSlide.tex
LOGO = $(TEMP-PWD)/logo.pdf

## SRC
FILE-README  = README
FILE-DICAS   = dicas
FILE-LISTA   = lista
FILE-ROTEIRO = handout

## MAKE
README:	$(FILE-README).md
	pandoc --template=$(TEMP-TEXT) $(FILE-README).md --variable logo=$(LOGO) -f markdown --latex-engine=pdflatex	-o $@.pdf

## MAKE
DICAS:	$(FILE-DICAS).md
	pandoc --template=$(TEMP-TEXT) $(FILE-DICAS).md --variable logo=$(LOGO) -f markdown --latex-engine=pdflatex	-o $@.pdf

%.tex: %.$(MEXT)

.PHONY : clean


