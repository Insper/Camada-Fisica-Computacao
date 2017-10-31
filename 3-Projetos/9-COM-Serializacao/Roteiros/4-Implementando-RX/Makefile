## Markdown extension (e.g. md, markdown, mdown).
MEXT = md

## Markdown Template
TEMP-PWD =/home/corsi/Dropbox/Insper/Markdown
TEMP-TEXT = $(TEMP-PWD)/InsperTemplate.tex
TEMP-SLIDE = $(TEMP-PWD)/InsperTemplateSlide.tex
LOGO = $(TEMP-PWD)/logo.pdf
LOGO-PNG = $(TEMP-PWD)/logo.png

## SRC
FILE-README  = README
FILE-SLIDE   = slides
FILE-LISTA   = lista
FILE-ROTEIRO = handout

## MAKE
README:	$(FILE-README).md
	pandoc --template=$(TEMP-TEXT) $(FILE-README).md --variable logo=$(LOGO) -f markdown --latex-engine=pdflatex	-o $@.pdf

LISTA:	$(FILE-LISTA).md
	pandoc --template=$(TEMP-TEXT) $(FILE-LISTA).md --variable logo=$(LOGO) -f markdown --latex-engine=pdflatex	-o $@.pdf

slides: $(FILE-SILDE)
	pandoc $(FILE-SLIDE).md --to=beamer --variable logo=$(LOGO-PNG) -f markdown --slide-level 2 --latex-engine=pdflatex	-o $(FILE-SLIDE).pdf

%.tex: %.$(MEXT)

.PHONY : clean


