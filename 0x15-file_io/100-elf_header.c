#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf_and_print_info(int elf_fd);

void close_elf(int elf_fd);

int main(int argc, char *argv[])
{
int elf_fd;

if (argc != 2)
{
fprintf(stderr, "Usage: %s <ELF file>\n", argv[0]);
return (EXIT_FAILURE);
}

elf_fd = open(argv[1], O_RDONLY);
if (elf_fd == -1)
{
perror("Error opening file");
return (EXIT_FAILURE);
}

check_elf_and_print_info(elf_fd);

close_elf(elf_fd);

return (EXIT_SUCCESS);
}

void check_elf_and_print_info(int elf_fd)
{
Elf64_Ehdr header;
ssize_t bytes_read;

bytes_read = read(elf_fd, &header, sizeof(Elf64_Ehdr));
if (bytes_read == -1)
{
perror("Error reading ELF header");
exit(EXIT_FAILURE);
}

/* Check if it's an ELF file */
if (header.e_ident[EI_MAG0] != ELFMAG0 ||
header.e_ident[EI_MAG1] != ELFMAG1 ||
header.e_ident[EI_MAG2] != ELFMAG2 ||
header.e_ident[EI_MAG3] != ELFMAG3)
{
fprintf(stderr, "Error: Not an ELF file\n");
exit(EXIT_FAILURE);
}

/* Print ELF header information */
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
{
printf("%02x ", header.e_ident[i]);
}
printf("\n");

printf("  Class:                             ");
switch (header.e_ident[EI_CLASS])
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
printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
}

printf("  Data:                              ");
switch (header.e_ident[EI_DATA])
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
printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
}

printf("  Version:                           %d", header.e_ident[EI_VERSION]);
switch (header.e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}

printf("  OS/ABI:                            ");
switch (header.e_ident[EI_OSABI])
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
printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
}

printf("  ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);

printf("  Type:                              ");
switch (header.e_type)
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
printf("<unknown: %x>\n", header.e_type);
}

printf("  Entry point address:               %#lx\n", header.e_entry);
}

void close_elf(int elf_fd)
{
if (close(elf_fd) == -1)
{
perror("Error closing file");
exit(EXIT_FAILURE);
}
}
