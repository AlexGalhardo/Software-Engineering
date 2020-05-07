#
#		Alex Galhardo Vieira
#		ICMC USP - São Carlos
#		2018

#		aleexgvieira@gmail.com
#		github.com/AlexGalhardo

#		makefile Playing with Java/Examples


JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java


CLASSES = \
        Caixa.java \
        Conta.java  

classes: $(CLASSES:.java=.class)

# build java classes
default: classes

# delete all java classes
clean:
		$(RM) *.class