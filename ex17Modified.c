#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX_DATA 512
#define MAX_ROWS 100

typedef struct Address{
	int id;
  	int set;
  	char name[MAX_DATA];  // MAX_DATA
  	char email[MAX_DATA]; // MAX_DATA
} Address;

typedef struct Database {
	Address rows[MAX_ROWS];
} Database;

typedef struct Connection{
  	// FILE struct defined by the C standard library that fopen, fread,
  	// fclose, and rewind work with.
  	FILE *file; 
  	Database *db;
} Connection;

// declaration of conn
Connection *conn = NULL;
// typedefing a pointer makes it look like you're dealing with an instance
// but you're really dealing with a pointer

void die(const char *message)
{
  	// When a function returns an error, it sents an "external" variable
  	// called errno to a number to say exactly what error happend. Print
  	// the error message using perror
  	if(errno) {
  		perror(message);
  	} else {
  		printf("ERROR: %s\n", message);
  	}

  	exit(1);
}

void Address_print(Address *addr) 
{
  	printf("%d %s %s\n", addr->id, addr->name, addr->email);
}

void Database_load()
{
	int rc = fread(conn->db, sizeof(Database), 1, conn->file);
	if(rc != 1) die("Failed to load database.");
}

void Database_open(const char *filename, char mode)
{
  	// struct Connection *conn = malloc(sizeof(struct Connection));

  	/*conn->db = malloc(sizeof(struct Database));
  	if(!conn->db) die("Memory error");
	*/

  	if(mode == 'c') {
		// conn.file (trying to access an instance when you have a *
		// or vice-versa)
  		conn->file = fopen(filename, "w");
  	} else {
  	  	conn->file = fopen(filename, "r+");

  		if(conn->file) {
  	  		Database_load();
  		}
  	}
  	if(!conn->file) die("Failed to open the file");
}


void Database_close()
{
  	  	if(conn->file) fclose(conn->file);
  	  	if(conn->db) free(conn->db);
		free(conn);
		
}


void Database_write()
{
  	rewind(conn->file);

	// writes from array in db to file in conn (size * nitems)
  	int rc = fwrite(conn->db, sizeof(struct Database), 1, conn->file);
  	if(rc != 1) die("Failed to write database.");

  	//rc = fflush(conn->file);
  	if(rc == -1) die("Cannot flush database.");
}

void Database_create()
{
  	int i = 0;
  	for(i = 0; i < MAX_ROWS; i++) {
  	        // make a prototype to initialize it
  	        struct Address addr = {.id = i, .set = 0};
  	        // then just assign it
  	        conn->db->rows[i] = addr;
  	} 
}

void Database_set(int id, const char *name, const char *email)
{
	
	Address *addr = &conn->db->rows[id];
    	if(addr->set) die("Already set, delete it first");

        addr->set = 1;
	// WARNING: bug, read the "How To Break It" and fix this
	char *res = strncpy(addr->name, name, MAX_DATA);
	// demonstrate the strncpy bug
	if(!res) die("Name copy failed");

	res = strncpy(addr->email, email, MAX_DATA);
	if(!res) die("Email copy failed");
}

void Database_get(int id)
{
  	struct Address *addr = &conn->db->rows[id];
  	
  	if(addr->set) {
  		Address_print(addr);
  	} else {
  		die("ID is not set");
  	}
}

void Database_delete(int id)
{
	Address addr = {.id = id, .set = 0};
	conn->db->rows[id] = addr;
}

void Database_list()
{
  	int i = 0;
  	Database *db = conn->db;
  	
  	for(i = 0; i < MAX_ROWS; i++) {
  	  	Address *cur = &db->rows[i];
  	  
  	  	if(cur->set) {
  	    		Address_print(cur);
  	  	}
  	}
}

int main(int argc, char *argv[])
{
	// intialization of conn
	// the compiler needs to allocate space for conn in the executable
	// DON'T NEED MALLOC WHEN CONN IS DEFINED ON THE STACK
	
	if(argc < 3) die("USAGE: ex17 <dbfile> <action> [action params]");

  	char *filename = argv[1];
  	char action = argv[2][0];
	Database_open(filename, action);
  	int id = 0;

	if(argc > 3) id = atoi(argv[3]);
	if(id >= MAX_ROWS) die("There's not that many records.");

  	switch(action) {
  		case 'c':
			Database_create();
			Database_write();
			break;

  		case 'g':
  		  	if(argc != 4) die("Need an id to get");

	  		Database_get(id);
  			break;

  		case 's':
  		  	if(argc != 6) die("Need id, name, email to set");

  		  	Database_set(id, argv[4], argv[5]);
  		  	Database_write();
  		  	break;

  		case 'd':
	  		if(argc != 4) die("Need id to delete");
	  		  
	  		Database_delete(id);
	  		Database_write();
	  		break;
	
  		case 'l':
	  		Database_list();
	  		break;
	
  		default:
  		  	die("Invalid action, only: c=create, g=get, s=set, d=del, l=list, f=find");
  	}

  	Database_close();

  	return 0;
}
