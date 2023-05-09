#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_file_elf(unsigned char *e_ident);
void print_file_magic(unsigned char *e_ident);
void print_file_class(unsigned char *e_ident);
void print_file_data(unsigned char *e_ident);
void print_file_version(unsigned char *e_ident);
void print_file_abi(unsigned char *e_ident);
void print_file_osabi(unsigned char *e_ident);
void print_file_type(unsigned int e_type, unsigned char *e_ident);
void print_file_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_file_elf(int elf_f);

/**
 * check_file_elf - a function that make sure the file is an ELF file.
 * @e_ident: A pointer 2ELF magic num
 * Description: exit code 98 if the file is not ELF
 */
void check_file_elf(unsigned char *e_ident)
{
	int i_of;

	for (i_of = 0; i_of < 4; i_of++)
	{
		if (e_ident[i_of] != 127 &&
		    e_ident[i_of] != 'E' &&
		    e_ident[i_of] != 'L' &&
		    e_ident[i_of] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_file_magic - Display d magic num
 * @e_ident: A pointer vaiable
 * Description: the num white space in between
 */
void print_file_magic(unsigned char *e_ident)
{
	int i_of;

	printf("  Magic:   ");

	for (i_of = 0; i_of < EI_NIDENT; i_of++)
	{
		printf("%02x", e_ident[i_of]);

		if (i_of == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_file_class - Display d class
 * @e_ident: A pointer variable
 */
void print_file_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_file_data - dispaly d data
 * @e_ident: the pointer
 */
void print_file_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_file_version - Display d version
 * @e_ident: d pointer
 */
void print_file_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * print_file_osabi - Display d OS/ABI
 * @e_ident: the pointer
 */
void print_file_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_file_abi - Display d ABI
 * @e_ident: the pointer
 */
void print_file_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * print_file_type - Display d type
 * @e_type: D type.
 * @e_ident: the pointer
 */
void print_file_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_file_entry - Display d entry
 * @e_entry: D address
 * @e_ident: the pointer
 */
void print_file_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_file_elf - ending the file.
 * @elf_f: D fd
 * Description: exit code 98 if not closed
 */
void close_file_elf(int elf_f)
{
	if (close(elf_f) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf_f);
		exit(98);
	}
}

/**
 * main - Print d information
 * @argc: all arguments in d program.
 * @argv: Pointer 2arguments.
 * Return: if success it will return 0
 * Description: exit code 98 if d file not ELF or function failed
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header_f;
	int open_f, read_f;

	open_f = open(argv[1], O_RDONLY);
	if (open_f == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header_f = malloc(sizeof(Elf64_Ehdr));
	if (header_f == NULL)
	{
		close_file_elf(open_f);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	read_f = read(open_f, header_f, sizeof(Elf64_Ehdr));
	if (read_f == -1)
	{
		free(header_f);
		close_file_elf(open_f);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_file_elf(header_f->e_ident);
	printf("ELF Header:\n");
	print_file_magic(header_f->e_ident);
	print_file_class(header_f->e_ident);
	print_file_data(header_f->e_ident);
	print_file_version(header_f->e_ident);
	print_file_osabi(header_f->e_ident);
	print_file_abi(header_f->e_ident);
	print_file_type(header_f->e_type, header_f->e_ident);
	print_file_entry(header_f->e_entry, header_f->e_ident);

	free(header_f);
	close_file_elf(open_f);
	return (0);
}
