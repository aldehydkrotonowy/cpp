// "Compilers: Principles, Techniques, and Tools" by Alfred Aho, Ravi Sethi, and Jeffrey Ullman.
// "Compiler Design in C", by A. C. Holub.
// "Crafting a Compiler", by C. Fischer and R. LeBlanc.
// "The Byte Book of Pascal", edited by Blaise W. Liffick.
// "Threaded Interpretive Languages", by R. G. Loeliger.
// "Compiler Construction: Principles and Practice", by Kenneth C. Louden.
// "The Art of Compiler Design: Theory and Practice", by Thomas Pittman & James Peters.
// "What Computing is All About", by Jan L.A. van de Snepscheut.
// "Compiling with C# and Java", by Pat Terry.
// "Programming Language Processors", by David A. Watt.
// "Algorithms + Data Structures = Programs", by Niklaus Wirth.
// "Compiler Construction", by Niklaus Wirth.


/*  getsym()
     -- skip white space
     while the char is a space or eol
         keep reading characters
     switch on the char
         when '+' read next char; return plus
         when '*' read next char; return times
         ...
         when 'a'..'z', 'A'..'Z':
             while the char is alphanumeric
                 accumulate characters in id
             return ident or keyword symbol, as appropriate
         when '0'..'9'
             while the char is a digit
                 accumulate the integer value in val
             return number
         otherwise
             read next char;
             return null
 end getsym */


// A simple scanner for a language with identifiers, integers,
// parenthesis, and plus and minus symbols.
#include <stdio.h>
#include <string.h>
#include <ctype.h>
enum {Ident_max = 16};
typedef char Ident[Ident_max+1];
typedef enum {null, times, plus, rparen, lparen, number, writesym, eofsym} Symbol;
class Scanner {
	public:
			bool init(const char fn[]);
			Symbol getsym();
			int getval() { return val; }
			const char *getid() { return id; }
	private:
			void read_ch();
			Symbol get_ident();
			Symbol get_number();
			void enter_kw(Symbol sym, Ident name);
			enum {KW=25};
			int val;
			Ident id;
			int ch;
			int nkw;
			char *keyTab[KW+1];
			Symbol keySym[KW+1];
			FILE *f;
};
void Scanner::read_ch() {
		ch = fgetc(f);
		if (ch != EOF)
				putchar((char)ch);
}
Symbol Scanner::get_ident() {
		int i;
		i = 0;
		do {
				if (i < Ident_max) {
						id[i] = (char)ch;
						i++;
				}
				read_ch();
		} while (ch != EOF && isalnum(ch));
		id[i] = '\0';
		for (i = 0; i < nkw && strcmp(id, keyTab[i]) != 0; i++);
		return keySym[i];
}
Symbol Scanner::get_number() {
		val = 0;
		do {
				val = 10 * val + (ch - '0');
				read_ch();
		} while (ch != EOF && isdigit(ch));
		return number;
}
Symbol Scanner::getsym() {
		while (ch != EOF && ch <= ' ')
				read_ch();
		switch (ch) {
				case EOF: return eofsym;
				case '+': read_ch(); return plus;
				case '*': read_ch(); return times;
				case '(': read_ch(); return lparen;
				case ')': read_ch(); return rparen;
				default:
						if (isalpha(ch))
								return get_ident();
						if (isdigit(ch))
								return get_number();
						read_ch();
						return null;
		}
}
void Scanner::enter_kw(Symbol sym, Ident name) {
		keyTab[nkw] = name;
		keySym[nkw] = sym;
		nkw++;
}
bool Scanner::init(const char fn[]) {
		if ((f = fopen(fn, "r")) == NULL)
				return false;
		ch = ' ';
		read_ch();
		nkw = 0;
		enter_kw(writesym,  "write");
		enter_kw(null,      "");
		return true;
}

int main(int argc, char *argv[]) {
		Scanner s;
		Symbol sym;
		if (argc < 2) {
				printf("Need a filename\n");
				return 2;
		}
		if (!s.init(argv[1])) {
				printf("Can't open %s\n", argv[1]);
				return 2;
		}
		do {
				sym = s.getsym();
		} while (sym != eofsym);
		return 0;
}