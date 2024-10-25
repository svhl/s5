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

## Day 5

### 20.

Implement the following simple PL/SQL programs.\
a. PL/SQL program to find the factorial of a number.

`SET SERVEROUTPUT ON;`

```
DECLARE
a number := &a;
b number := 1;
c number := 1;
BEGIN
WHILE b <= a LOOP
c := c * b;
b := b + 1;
END LOOP;
DBMS_OUTPUT.PUT_LINE('Factorial = ' || c);
END;
/
```

b. PL/SQL program to reverse a string.

```
DECLARE
str varchar(50) := '&str';
rev varchar(50);
len number := LENGTH(str);
BEGIN
FOR i IN REVERSE 1..len LOOP
rev := rev || SUBSTR(str, i, 1);
END LOOP;
DBMS_OUTPUT.PUT_LINE('Reversed string: ' || rev);
END;
/
```

### 21.

Implementation of various control structures using PL/SQL.\
a. Write a PL/SQL code block to calculate the area of a circle for a value of radius varying from 5 to 15. Store the radius & the corresponding values of calculated area in an empty table named areas, consisting of 2 columns - radius & area.

`CREATE TABLE areas(radius number, area number);`

```
DECLARE
rad number;
ar number;
BEGIN
FOR rad IN 5..15 LOOP
ar := 3.14 * rad * rad;
INSERT INTO areas VALUES(rad, ar);
END LOOP;
END;
/
```

b. Write a PL/SQL code block that will accept an account number from the user, check if the user's balance is less than minimum balance, then deduct 100 from the balance.

`CREATE TABLE accounts(accnum int PRIMARY KEY, balance number);`

`INSERT INTO accounts VALUES(12345, 400);`

```
DECLARE
ano number := &ano;
bal number;
min number := 500;
BEGIN
SELECT balance INTO bal FROM accounts WHERE accnum = ano;
IF bal < min THEN
bal := bal - 100;
UPDATE accounts SET balance = bal WHERE accnum = ano;
DBMS_OUTPUT.PUT_LINE('New balance = ' || bal);
ELSE
DBMS_OUTPUT.PUT_LINE('Balance greater than minimum balance');
END IF;
EXCEPTION
WHEN NO_DATA_FOUND THEN
DBMS_OUTPUT.PUT_LINE('Error: Account number does not exist');
WHEN OTHERS THEN
DBMS_OUTPUT.PUT_LINE('Error: ' || SQLERRM);
END;
/
```

## Day 6

### 22.

Creation of procedures & functions.
a. Create a procedure which decreases the fine of the given reader from the Readers table by 5% if the total fine is greater than 100.

`ALTER TABLE readers ADD fine number DEFAULT 0;`

`UPDATE return SET fine = 110 WHERE user_id = 'L0004';`

`UPDATE readers SET fine = 200 WHERE user_id = 'L0004';`

```
CREATE OR REPLACE PROCEDURE finereplace
AS
BEGIN
UPDATE readers SET fine = fine - (0.05 * fine) WHERE user_id IN(SELECT user_id FROM return GROUP BY user_id HAVING SUM(fine) > 100);
END;
/
```

```
BEGIN
finereplace;
END;
/
```

b. Write a procedure to add "not returned" status to the books which are not returned after the due date.

`ALTER TABLE return ADD status varchar(50);`

```
CREATE OR REPLACE PROCEDURE returnstatus
AS
BEGIN
UPDATE return SET status = 'not returned' WHERE return_date IS NULL AND due_date < (SELECT SYSDATE FROM DUAL);
END;
/
```

```
BEGIN
returnstatus;
END;
/
```

c. Write a function which returns the no. of copies of book given the author ID.

```
CREATE OR REPLACE FUNCTION copies(auth varchar2)
RETURN varchar2
IS
noc int;
BEGIN
SELECT SUM(noofcopies) INTO noc FROM books WHERE authorno = auth GROUP BY authorno;
RETURN ('No. of copies: ' || noc);
END;
/
```

```
DECLARE
noc varchar2(50);
BEGIN
noc := copies('A002');
DBMS_OUTPUT.PUT_LINE(noc);
END;
/
```

d. Create a function which returns the date of return of all books for a particular reader if the user ID is given.

```
CREATE OR REPLACE FUNCTION retdateofbooks(uid varchar2)
RETURN varchar2
IS
retdate varchar2(100);
BEGIN
SELECT return_date INTO retdate FROM return WHERE user_id = uid AND ROWNUM = 1;
RETURN('Return date: ' || retdate);
END;
/
```

```
DECLARE
retdate varchar2(100);
BEGIN
retdate := retdateofbooks('L0005');
DBMS_OUTPUT.PUT_LINE(retdate);
END;
/
```

## Day 7

### 23.

Create a cursor which updates the fine of a reader as follows:\
i. If fine < 100 then update fine to 100.

```
DECLARE
cur_fine return.fine%type;
CURSOR c1 IS
SELECT fine FROM return WHERE fine < 100 FOR UPDATE;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO cur_fine;
EXIT WHEN c1%NOTFOUND;
UPDATE return SET fine = 100 WHERE CURRENT OF c1;
END LOOP;
CLOSE c1;
END;
/
```

ii. If fine >= 100 and < 150 then update fine to 150.

```
DECLARE
cur_fine return.fine%type;
CURSOR c1 IS
SELECT fine FROM return WHERE fine >= 100 AND fine < 150 FOR UPDATE;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO cur_fine;
EXIT WHEN c1%NOTFOUND;
UPDATE return SET fine = 150 WHERE CURRENT OF c1;
END LOOP;
CLOSE c1;
END;
/
```

iii. If fine >= 150 and < 200 then update fine to 200.

```
DECLARE
cur_fine return.fine%type;
CURSOR c1 IS
SELECT fine FROM return WHERE fine >= 150 AND fine < 200 FOR UPDATE;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO cur_fine;
EXIT WHEN c1%NOTFOUND;
UPDATE return SET fine = 200 WHERE CURRENT OF c1;
END LOOP;
CLOSE c1;
END;
/
```

iv. Count the no. of records that have been updated.

```
DECLARE
cur_fine return.fine%type;
cur_count NUMBER := 0;
CURSOR c1 IS
SELECT fine FROM return;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO cur_fine;
EXIT WHEN c1%NOTFOUND;
IF cur_fine <= 200 THEN
cur_count := cur_count + 1;
END IF;
END LOOP;
CLOSE c1;
dbms_output.put_line('No. of records updated: ' || cur_count);
END;
/
```

### 24.

Create a cursor to update the due date for a particular book to 15 days if more than 3 reserves exit.

`INSERT INTO return VALUES('29-OCT-2024', NULL, NULL, '29-NOV-2024', 0, 'L0004', 56789, NULL);`

```
DECLARE
r_isbn return.isbn%type;
CURSOR c1 IS
SELECT isbn FROM return GROUP BY isbn HAVING COUNT(reserve_date) > 3;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO r_isbn;
EXIT WHEN c1%NOTFOUND;
UPDATE return SET due_date = reserve_date + 15 WHERE isbn = r_isbn;
END LOOP;
CLOSE c1;
END;
/
```

### 25.

Create a cursor to increase the no. of copies of books as follows:\
i. If no. of copies < 5 then update to 8.

```
DECLARE
v_isbn books.isbn%type;
v_no_of_copies books.noofcopies%type;
CURSOR c1 IS 
SELECT noofcopies FROM books FOR UPDATE;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO v_no_of_copies;
EXIT when c1%NOTFOUND;
IF v_no_of_copies < 5 THEN
UPDATE books SET noofcopies = 8 WHERE CURRENT OF c1;
END IF;
END LOOP;
END;
/
```

ii. If no. of copies < 10 then update to 12.

```
DECLARE
v_isbn books.isbn%type;
v_no_of_copies books.noofcopies%type;
CURSOR c1 IS 
SELECT noofcopies FROM books FOR UPDATE;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO v_no_of_copies;
EXIT when c1%NOTFOUND;
IF v_no_of_copies < 10 THEN
UPDATE books SET noofcopies = 12 WHERE CURRENT OF c1;
END IF;
END LOOP;
END;
/
```

iii. If no. of copies < 15 then update to 17.

```
DECLARE
v_isbn books.isbn%type;
v_no_of_copies books.noofcopies%type;
CURSOR c1 IS 
SELECT noofcopies FROM books FOR UPDATE;
BEGIN
OPEN c1;
LOOP
FETCH c1 INTO v_no_of_copies;
EXIT when c1%NOTFOUND;
IF v_no_of_copies < 15 THEN
UPDATE books SET noofcopies = 17 WHERE CURRENT OF c1;
END IF;
END LOOP;
END;
/
```
