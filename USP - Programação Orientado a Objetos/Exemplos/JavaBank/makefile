#
#		Alex Galhardo Vieira
#		ICMC USP - São Carlos
#		2018

#		aleexgvieira@gmail.com
#		github.com/AlexGalhardo

#		makefile Playing with Java/JavaBank


JFLAGS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	$(JC) $(JFLAGS) $*.java


CLASSES = \
        Main.java \
        JavaBankAccount.java \
        Pessoa.java 

classes: $(CLASSES:.java=.class)

# build java classes
default: classes

# delete all java classes
clean:
		$(RM) *.class