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
i. Readers

`ALTER TABLE reports MODIFY user_id varchar(10);`

`ALTER TABLE readers MODIFY(user_id varchar(10), email varchar(20) UNIQUE);`

ii. Books

`ALTER TABLE keeps_track_of MODIFY user_id varchar(10);`

`ALTER TABLE phone_no MODIFY phone_no int DEFAULT 0;`

`ALTER TABLE reserve_return_date MODIFY user_id varchar(10);`

`ALTER TABLE books MODIFY isbn varchar(10);`

iii. Return

`CREATE TABLE return(reserve_date date, userid int, issue_date date, return_date date, due_date date, user_id varchar(10), isbn varchar(10), FOREIGN KEY (user_id) REFERENCES readers(user_id), FOREIGN KEY (isbn) REFERENCES books(isbn));`

###  3.

Modifying tables.\
a. Add a column Fine to the Return table. The data type is number & set default to 0.

`ALTER TABLE return ADD fine number DEFAULT 0;`

b. Add a column Total no. of copies to the Books table. The data type is number.

`ALTER TABLE books ADD total_no_of_copies number;`

c. Modify the column width of the FirstName field of Readers table to 25.

`ALTER TABLE readers MODIFY firstname varchar(25);`

d. Add a foreign key constraint on Reports table.

`ALTER TABLE reports ADD isbn varchar(10);`

`ALTER TABLE reports MODIFY FOREIGN KEY (isbn) REFERENCES books(isbn);`

e. Display all tables currently available to the user.

`SELECT table_name FROM user_tables;`

f. Drop the table Maintains.

`DROP TABLE maintain;`

## Day 2

### 4.

Performing DML commands like insertion, deletion, modifying, altering & updating records based on conditions.\
a. Create & insert the following values in Readers table.

`CREATE TABLE readers(user_id varchar(5) PRIMARY KEY, email varchar(50), firstname varchar(50), lastname varchar(50), phoneno int, address varchar(50));`

`INSERT INTO readers VALUES('L0001', 'tom@gmail.com', 'Frank', 'Tom', 422544, 'NY');`

`INSERT INTO readers VALUES('L0002', 'bob@gmail.com', 'Elliot', 'Bob', 435678, 'NY');`

`INSERT INTO readers VALUES('L0003', 'ann@gmail.com', 'Calf', 'Ann', 234908, 'Dallas');`

`INSERT INTO readers VALUES('L0004', 'harry@gmail.com', 'Potter', 'Harry', 112466, 'Seattle');`

`INSERT INTO readers VALUES('L0005', 'smith@gmail.com', 'Daniel', 'Haik', 982222, 'Seattle');`

`INSERT INTO readers VALUES('L0006', 'dick@gmail.com', 'Xame', 'Dick', 876987, 'NJ');`

b. Create & insert the following values in Books table.

`CREATE TABLE books(isbn int PRIMARY KEY, authorno varchar(4), title varchar(50), publisher varchar(50), noofcopies int);`

`INSERT INTO books VALUES(12345, 'A001', 'Fundamentals of Java', 'Pearson', 1);`

`INSERT INTO books VALUES(54321, 'A002', 'Computer Networks', 'Pearson', 5);`

`INSERT INTO books VALUES(34561, 'A002', 'Operating System', 'MK', 10);`

`INSERT INTO books VALUES(16543, 'A004', 'Microprocessors', 'Wiley', 10);`

`INSERT INTO books VALUES(98765, 'A005', 'Internet of Things', 'McKane', 8);`

`INSERT INTO books VALUES(56789, 'A005', 'Artificial Intelligence', 'BPB', 3);`

c. Create & insert the following values in Return table.

`CREATE TABLE return(reserve_date date, return_date date, issue_date date, due_date date, fine int, user_id varchar(5), isbn int);`

`INSERT INTO return VALUES('10-AUG-24', NULL, '10-AUG-24', '30-AUG-24', 0, 'L0006', 56789);`

`INSERT INTO return VALUES('10-AUG-24', '01-SEP-24', '10-AUG-24', '30-AUG-24', 8, 'L0005', 98765);`

`INSERT INTO return VALUES('11-AUG-24', NULL, NULL, NULL, 0, 'L0005', 16543);`

`INSERT INTO return VALUES('12-AUG-24', NULL, '14-AUG-24', '04-SEP-24', 0, 'L0004', 56789);`

`INSERT INTO return VALUES('12-AUG-24', '25-AUG-24', '18-AUG-24', '08-SEP-24', 20, 'L0001', 12345);`

`INSERT INTO return VALUES('13-AUG-24', NULL, NULL, NULL, 0, 'L0001', 56789);`

### 5.

Display the entire contents of all the tables.

`SELECT * FROM readers;`

`SELECT * FROM books;`

`SELECT * FROM return;`

### 6.

Display the email IDs and cities of readers of the library.

`SELECT email, address AS city FROM readers;`

### 7.

Display details of all users who belong to NY.

`SELECT * FROM readers WHERE address = 'NY';`

### 8.

Display details of all books published by Pearson.

`SELECT * FROM books WHERE publisher = 'Pearson';`

### 9.

Display details of authors who publish with both Pearson and MK.

`SELECT * FROM books WHERE publisher IN('Pearson', 'MK') AND authorno IN(SELECT authno FROM books WHERE publisher IN('Pearson', 'MK') GROUP BY authorno HAVING COUNT(DISTINCT publisher) = 2);`

### 10.

Display details of all book titles which have more than 5 copies in the library.

`SELECT * FROM books WHERE noofcopies > 5;`

### 11.

Display all readers whose names start with H.

`SELECT * FROM readers WHERE firstname LIKE 'H%' OR lastname LIKE 'H%';`

### 12.

Display all readers whose names end with K.

`SELECT * FROM readers WHERE firstname LIKE '%k' OR lastname LIKE '%k';`

## Day 3

### 13.

Implementation of set operators, nested queries & join queries.\
a. Get the list of book titles that are issued but not returned.

`SELECT TITLE FROM books WHERE isbn IN(SELECT isbn FROM return WHERE return_date IS NULL);`

b. Get the list of users who have read Artificial Inteliigence

`SELECT r.firstname, r.lastname FROM readers r JOIN return ret ON r.user_id = ret.user_id WHERE ret.isbn = (SELECT isbn FROM books WHERE title = 'Artificial Intelligence');`

c. Get the total fine collected for the current month.

`SELECT SUM(fine) AS totalfine FROM return WHERE EXTRACT(YEAR FROM return_date) = EXTRACT(YEAR FROM SYSDATE) AND EXTRACT(MONTH FROM return_date) = EXTRACT(MONTH FROM SYSDATE);`

d. Get the list of users who have not returned the books before due date.

`SELECT r.firstname, r.lastname FROM readers r JOIN return ret ON r.user_id = ret.user_id WHERE ret.return_date > ret.due_date;`

e. Get the list of users who have not taken any books.

`SELECT * FROM readers WHERE user_id NOT IN(SELECT DISTINCT user_id FROM return);`

f. Get the list of authors who have written more than one book.

`SELECT authorno FROM books GROUP BY authorno HAVING COUNT(*) > 1;`

### 14.

Implementation of order by, group by, and having clause.\
a. Display the reader names in ascending order.

`SELECT firstname, lastname FROM readers ORDER BY firstname;`

b. Determine the maximum fine obtained for each book.

`SELECT isbn, MAX(fine) as maxfine FROM return GROUP BY isbn;`

### 15.

Implementation of various aggregate functions in SQL.\
a. Display the number of books written by each author.

`SELECT authorno, COUNT(isbn) AS noofbooks FROM books GROUP BY authorno;`

b. Calculate the total fine obtained by the library as of date.

`SELECT SUM(fine) AS totalfine FROM return WHERE return_date <= SYSDATE;`

c. Count the total number of records in the Readers table.

`SELECT COUNT(*) AS total FROM readers;`

d. Display the list of publishers & the number of books published by each publisher.

`SELECT publisher, COUNT(isbn) AS noofbooks FROM books GROUP BY publisher;`

## Day 4

### 16.

Practice of SQL TCL commands like rollback, commit and savepoint.\
a. Delete all users who have not yet borrowed a book.

`DELETE FROM readers WHERE user_id NOT IN(SELECT user_id FROM readers WHERE user_id IN(SELECT user_id FROM return));`

b. Write a query to undo the above delete query.

`ROLLBACK;`

### 17.

Practice of SQL DCL commands for granting & revoking user privileges.\
a. Write a query to grant all privileges of Users table to nearby user.

`CREATE TABLE users(userid int);`

`GRANT ALL PRIVILEGES ON users TO u1234567;`

b. Write a query to grant some privileges of Return table to nearby user.

`GRANT SELECT, INSERT, UPDATE ON return TO u1234567;`

c. Write a query to revoke all privileges of Users table from the user.

`REVOKE ALL PRIVILEGES ON users FROM u1234567;`

d. Write a query to revoke some privileges of Return table from the user.`

`REVOKE SELECT, INSERT, UPDATE ON return FROM u1234567;`

### 18.

Creation of views.\
a. Create a view Reader_VW of Employee table with the following columns.

`CREATE VIEW Reader_VW AS SELECT user_id, lastname, address FROM readers;`

b. Update Reader_VW by changing NY to New York.

`UPDATE Reader_VW SET address = 'New York' WHERE address = 'NY';`

c. Delete the reader Ann from Reader_VW.

`DELETE FROM Reader_VW WHERE lastname = 'Ann';`

d. Delete the view created.

`DROP VIEW Reader_VW;`

### 19.

Implementation of built-in functions in RDBMS.\
a. Find the value of 16^5.

`SELECT POWER(16, 5) FROM dual;`

b. Find the length of the string "Application".

`SELECT LENGTH("Application") FROM dual;`

c. Find the last day of the current month.

`SELECT LAST_DAY(SYSDATE) FROM dual;`

d. Convert the number 65432 to $65432. Use format mask.

`SELECT TO_CHAR(65432, '$99999') FROM dual;`

e. Display the current system date & time with fractional seconds & timezone.

`SELECT SYSTIMESTAMP FROM dual;`

f. Find the number of book titles available.

`SELECT COUNT(DISTINCT title) FROM books;`

g. Display the due date of entries in Return table in the following format: Friday, 11th August, 2017

`SELECT TO_CHAR(due_date, 'Day, DDth Month, YYYY') FROM return;`
