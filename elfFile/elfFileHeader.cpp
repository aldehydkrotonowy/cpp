#include <elf.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <iostream>

// typedef struct {
//   uint8_t     e_ident[16];         /* Magic number and other info */
//   uint16_t    e_type;              /* Object file type */
//   uint16_t    e_machine;           /* Architecture */
//   uint32_t    e_version;           /* Object file version */
//   uint64_t    e_entry;             /* Entry point virtual address */
//   uint64_t    e_phoff;             /* Program header table file offset */
//   uint64_t    e_shoff;             /* Section header table file offset */
//   uint32_t    e_flags;             /* Processor-specific flags */
//   uint16_t    e_ehsize;            /* ELF header size in bytes */
//   uint16_t    e_phentsize;         /* Program header table entry size */
//   uint16_t    e_phnum;             /* Program header table entry count */
//   uint16_t    e_shentsize;         /* Section header table entry size */
//   uint16_t    e_shnum;             /* Section header table entry count */
//   uint16_t    e_shstrndx;          /* Section header string table index */
// } Elf64Hdr;

// typedef struct elf64_phdr {
//   Elf64_Word p_type;
//   Elf64_Word p_flags;
//   Elf64_Off p_offset;		/* Segment file offset */
//   Elf64_Addr p_vaddr;		/* Segment virtual address */
//   Elf64_Addr p_paddr;		/* Segment physical address */
//   Elf64_Xword p_filesz;		/* Segment size in file */
//   Elf64_Xword p_memsz;		/* Segment size in memory */
//   Elf64_Xword p_align;		/* Segment alignment, file & memory */
// } Elf64_Phdr;

void read_elf_header(const char* elfFile, const char* outputFile) {
	// switch to Elf32_Ehdr for x86 architecture.
	Elf64_Ehdr header;
	Elf64_Phdr fileHeader;
	char separator[] = "--------------------------------";

	FILE* file = fopen(elfFile, "rb");
	if(file) {
		// read the header
		fread(&header, 1, sizeof(header), file);

		// check so its really an elf file
		// header.e_ident - pointer to memory
		// EFLMAG - pointer to memory 2
		// SELFMAG - number of bytes to compare
		if (memcmp(header.e_ident, ELFMAG, SELFMAG) == 0) {
			 // this is a valid elf file

			std::cout<<"this is a valid elf file \n";
			 // write the header to the output file

			 FILE* fout = fopen(outputFile, "wb");
			 if(fout) {
				 	fwrite(&header, 1, sizeof(header), fout);
				 	fwrite(&separator, sizeof(char), sizeof(separator), fout);
				 	fwrite(&fileHeader, 1, sizeof(fileHeader), fout);
					fwrite(&separator, sizeof(char), sizeof(separator), fout);
				 	fclose(fout);
			 }
			 std::cout<<"e_phoff is: "<<header.e_phoff<<std::endl;
		}

		// finally close the file
		fclose(file);
	}
}

int main(int argc, char* argv[]){
		
		std::cout << "You have entered " << argc  << " arguments:" << "\n"; 
	
		for (int i = 0; i < argc; ++i) {
				std::cout << i << ". "<< argv[i] << "\n"; 
		}

		char* fileName = argv[1];
		char* fileOut = argv[2];

		std::cout<< "\n\nstart reading header \n";

		read_elf_header(fileName, fileOut);

	return 0;
}