# DBMS

## Day 1

### 1.

Design & creation of database schema & tables with the ER diagram for library management system.

`CREATE SCHEMA AUTHORIZATION [UID];`

`CREATE TABLE reports(reg_no int PRIMARY KEY, user_id int, book_no int, issue_return date);`

`CREATE TABLE staff(staff_id int PRIMARY KEY, name varchar(50));`

`CREATE TABLE readers(user_id int PRIMARY KEY, email varchar(50), firstname varchar(50), lastname varchar(50), address varchar(50));`

`CREATE TABLE phone_no(user_id int, phone_no int);`

`CREATE TABLE books(isbn int PRIMARY KEY, authno int, title varchar(50), category varchar(50), edition varchar(50), price number(7,2));`

`CREATE TABLE publication(author_id int PRIMARY KEY, publication varchar(50), name varchar(50));`

`CREATE TABLE authentication_system(login_id int PRIMARY KEY, password int);`

`CREATE TABLE manages(reg_no int PRIMARY KEY, staff_id int);`

`CREATE TABLE keeps_track_of(staff_id int, user_id int, PRIMARY KEY(staff_id, user_id));`

`CREATE TABLE reserve_return_date(reserve_date date, return_date date, user_id int, isbn int, PRIMARY KEY(reserve_date, isbn));`

`CREATE TABLE maintain(isbn int PRIMARY KEY, staff_id int);`

`CREATE TABLE login(staff_id int PRIMARY KEY, login_id int);`

### 2.

Creation of a database using DDL commands. Create the following tables:\
i. Readers\
ii. Books\
iii. Return

`ALTER TABLE reports MODIFY user_id varchar(10);`

`ALTER TABLE readers MODIFY(user_id varchar(10), email varchar(20) UNIQUE);`

`ALTER TABLE keeps_track_of MODIFY user_id varchar(10);`

`ALTER TABLE phone_no MODIFY phone_no int DEFAULT 0;`

`ALTER TABLE reserve_return_date MODIFY user_id varchar(10);`

`ALTER TABLE books MODIFY isbn varchar(10);`

`CREATE TABLE return(reserve_date date, userid int, issue_date date, return_date date, due_date date, user_id varchar(10), isbn varchar(10), FOREIGN KEY (user_id) REFERENCES readers(user_id), FOREIGN KEY (isbn) REFERENCES books(isbn));`

###  3.

Modifying tables.\
a. Add a column Fine to the Return table. The data type is number & set default to 0.\
b. Add a column Total no. of copies to the Books table. The data type is number.\
c. Modify the column width of the FirstName field of Readers table to 25.\
d. Add a foreign key constraint on Reports table.\
e. Display all tables currently available to the user.\
f. Drop the table Maintains.

`ALTER TABLE return ADD fine number DEFAULT 0;`

`ALTER TABLE books ADD total_no_of_copies number;`

`ALTER TABLE readers MODIFY firstname varchar(25);`

`ALTER TABLE reports ADD isbn varchar(10);`

`ALTER TABLE reports MODIFY FOREIGN KEY (isbn) REFERENCES books(isbn);`

`SELECT table_name FROM user_tables;`

`DROP TABLE maintain;`

## Day 2

### 4.

`CREATE TABLE readers(user_id varchar(5) PRIMARY KEY, email varchar(50), firstname varchar(50), lastname varchar(50), phoneno int, address varchar(50));`

`INSERT INTO readers VALUES('L0001', 'tom@gmail.com', 'Frank', 'Tom', 422544, 'NY');`

`INSERT INTO readers VALUES('L0002', 'bob@gmail.com', 'Elliot', 'Bob', 435678, 'NY');`

`INSERT INTO readers VALUES('L0003', 'ann@gmail.com', 'Calf', 'Ann', 234908, 'Dallas');`

`INSERT INTO readers VALUES('L0004', 'harry@gmail.com', 'Potter', 'Harry', 112466, 'Seattle');`

`INSERT INTO readers VALUES('L0005', 'smith@gmail.com', 'Daniel', 'Haik', 982222, 'Seattle');`

`INSERT INTO readers VALUES('L0006', 'dick@gmail.com', 'Xame', 'Dick', 876987, 'NJ');`

`CREATE TABLE books(isbn int PRIMARY KEY, authorno varchar(4), title varchar(50), publisher varchar(50), noofcopies int);`

`INSERT INTO books VALUES(12345, 'A001', 'Fundamentals of Java', 'Pearson', 1);`

`INSERT INTO books VALUES(54321, 'A002', 'Computer Networks', 'Pearson', 5);`

`INSERT INTO books VALUES(34561, 'A002', 'Operating System', 'MK', 10);`

`INSERT INTO books VALUES(16543, 'A004', 'Microprocessors', 'Wiley', 10);`

`INSERT INTO books VALUES(98765, 'A005', 'Internet of Things', 'McKane', 8);`

`INSERT INTO books VALUES(56789, 'A005', 'Artificial Intelligence', 'BPB', 3);`

`CREATE TABLE return(reserve_date date, return_date date, issue_date date, due_date date, fine int, user_id varchar(5), isbn int);`

`INSERT INTO return VALUES('10-AUG-24', NULL, '10-AUG-24', '30-AUG-24', 0, 'L0006', 56789);`

`INSERT INTO return VALUES('10-AUG-24', '01-SEP-24', '10-AUG-24', '30-AUG-24', 8, 'L0005', 98765);`

`INSERT INTO return VALUES('11-AUG-24', NULL, NULL, NULL, 0, 'L0005', 16543);`

`INSERT INTO return VALUES('12-AUG-24', NULL, '14-AUG-24', '04-SEP-24', 0, 'L0004', 56789);`

`INSERT INTO return VALUES('12-AUG-24', '25-AUG-24', '18-AUG-24', '08-SEP-24', 20, 'L0001', 12345);`

`INSERT INTO return VALUES('13-AUG-24', NULL, NULL, NULL, 0, 'L0001', 56789);`

### 5.

`SELECT * FROM readers;`

`SELECT * FROM books;`

`SELECT * FROM return;`

### 6.

`SELECT email, address AS city FROM readers;`

### 7.

`SELECT * FROM readers WHERE address = 'NY';`

### 8.

`SELECT * FROM books WHERE publisher = 'Pearson';`

### 9.

`SELECT * FROM books WHERE publisher IN('Pearson', 'MK') AND authorno IN(SELECT authno FROM books WHERE publisher IN('Pearson', 'MK') GROUP BY authorno HAVING COUNT(DISTINCT publisher) = 2);`

### 10.

`SELECT * FROM books WHERE noofcopies > 5;`

### 11.

`SELECT * FROM readers WHERE firstname LIKE 'H%' OR lastname LIKE 'H%';`

### 12.

`SELECT * FROM readers WHERE firstname LIKE '%k' OR lastname LIKE '%k';`
