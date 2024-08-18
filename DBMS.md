# DBMS

## Day 1

### 1.

Design & creation of database schema & tables with the ER diagram for library management system.

`CREATE SCHEMA AUTHORIZATION [UID];`

`CREATE TABLE reports(reg_no int PRIMARY KEY user_id int, book_no int, issue_return date);`

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
