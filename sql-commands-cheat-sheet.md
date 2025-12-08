# SQL Commands Cheat Sheet

### Data Definition Language (DDL)

### Create Table

```sql
CREATE TABLE table_name (
    column1 datatype PRIMARY KEY,
    column2 datatype,
    column3 datatype,
   ....
);
```

### Drop Table

```sql
DROP TABLE table_name;
```

### Alter Table

```sql
ALTER TABLE table_name
ADD column_name datatype;

ALTER TABLE table_name
DROP COLUMN column_name;

ALTER TABLE table_name
MODIFY COLUMN column_name datatype;
```

### Rename Table

```sql
ALTER TABLE old_table_name
RENAME TO new_table_name;
```

## Data Manipulation Language (DML)

### Insert Data

```sql
INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);
```

### Update Data

```sql
UPDATE table_name
SET column1 = value1, column2 = value2, ...
WHERE condition;
```

### Delete Data

```sql
DELETE FROM table_name
WHERE condition;
```

### Select Data

```sql
SELECT column1, column2, ...
FROM table_name
WHERE condition;

SELECT * FROM table_name;
```

## Data Query Language (DQL)

### Select with Join

```sql
SELECT table1.column1, table2.column2, ...
FROM table1
JOIN table2 ON table1.common_column = table2.common_column;
```

### Select with Alias

```sql
SELECT column_name AS alias_name
FROM table_name;
```

### Select with Aggregate Functions

```sql
SELECT COUNT(column_name)
FROM table_name
WHERE condition;

SELECT AVG(column_name)
FROM table_name
WHERE condition;

SELECT SUM(column_name)
FROM table_name
WHERE condition;

SELECT MAX(column_name)
FROM table_name
WHERE condition;

SELECT MIN(column_name)
FROM table_name
WHERE condition;
```

## Data Control Language (DCL)

### Grant Privileges

```sql
GRANT ALL PRIVILEGES ON database_name.* TO 'username'@'host';

GRANT SELECT, INSERT, UPDATE, DELETE ON database_name.table_name TO 'username'@'host';
```

### Revoke Privileges

```sql
REVOKE ALL PRIVILEGES ON database_name.* FROM 'username'@'host';

REVOKE SELECT, INSERT, UPDATE, DELETE ON database_name.table_name FROM 'username'@'host';
```

## Transaction Control Language (TCL)

### Begin Transaction

```sql
START TRANSACTION;
```

### Commit Transaction

```sql
COMMIT;
```

### Rollback Transaction

```sql
ROLLBACK;
```

### Savepoint

```sql
SAVEPOINT savepoint_name;
```

### Rollback to Savepoint

```sql
ROLLBACK TO SAVEPOINT savepoint_name;
```

## Indexes

### Create Index

```sql
CREATE INDEX index_name
ON table_name (column1, column2, ...);
```

### Drop Index

```sql
DROP INDEX index_name;
```

## Views

### Create View

```sql
CREATE VIEW view_name AS
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

### Drop View

```sql
DROP VIEW view_name;
```

## Useful Clauses

### Order By

```sql
SELECT column1, column2, ...
FROM table_name
ORDER BY column1 ASC|DESC;
```

### Group By

```sql
SELECT column1, COUNT(*)
FROM table_name
GROUP BY column1;
```

### Having

```sql
SELECT column1, COUNT(*)
FROM table_name
GROUP BY column1
HAVING COUNT(*) > value;
```

### Limit

```sql
SELECT column1, column2, ...
FROM table_name
LIMIT number;
```

## String Functions

### Concatenate

```sql
SELECT CONCAT(column1, column2) AS new_column
FROM table_name;
```

### Substring

```sql
SELECT SUBSTRING(column_name, start, length) AS new_column
FROM table_name;
```

### Replace

```sql
SELECT REPLACE(column_name, 'old_value', 'new_value') AS new_column
FROM table_name;
```

## Date Functions

### Current Date

```sql
SELECT CURRENT_DATE;
```

### Current Time

```sql
SELECT CURRENT_TIME;
```

### Date Add

```sql
SELECT DATE_ADD(column_name, INTERVAL value DAY) AS new_date
FROM table_name;
```

### Date Sub

```sql
SELECT DATE_SUB(column_name, INTERVAL value DAY) AS new_date
FROM table_name;
```

## Case Statements

### Case

```sql
SELECT column_name,
    CASE
        WHEN condition1 THEN result1
        WHEN condition2 THEN result2
        ELSE result
    END AS new_column
FROM table_name;
```

## SQL JOIN Commands Cheat Sheet

### Syntax

```sql
SELECT columns
FROM table1
INNER JOIN table2
ON table1.column = table2.column;
```

### Example

```sql
SELECT employees.name, departments.name
FROM employees
INNER JOIN departments
ON employees.department_id = departments.id;
```

## LEFT JOIN (or LEFT OUTER JOIN)

Returns all records from the left table (table1), and the matched records from the right table (table2). The result is NULL from the right side if there is no match.

### Syntax

```sql
SELECT columns
FROM table1
LEFT JOIN table2
ON table1.column = table2.column;
```

### Example

```sql
SELECT employees.name, departments.name
FROM employees
LEFT JOIN departments
ON employees.department_id = departments.id;
```

## RIGHT JOIN (or RIGHT OUTER JOIN)

Returns all records from the right table (table2), and the matched records from the left table (table1). The result is NULL from the left side when there is no match.

### Syntax

```sql
SELECT columns
FROM table1
RIGHT JOIN table2
ON table1.column = table2.column;
```

### Example

```sql
SELECT employees.name, departments.name
FROM employees
RIGHT JOIN departments
ON employees.department_id = departments.id;
```

## FULL JOIN (or FULL OUTER JOIN)

Returns all records when there is a match in either left (table1) or right (table2) table records. The result is NULL from the side where there is no match.

### Syntax

```sql
SELECT columns
FROM table1
FULL JOIN table2
ON table1.column = table2.column;
```

### Example

```sql
SELECT employees.name, departments.name
FROM employees
FULL JOIN departments
ON employees.department_id = departments.id;
```

## CROSS JOIN

Returns the Cartesian product of both tables. This means it returns all possible combinations of rows from both tables.

### Syntax

```sql
SELECT columns
FROM table1
CROSS JOIN table2;
```

### Example

```sql
SELECT employees.name, departments.name
FROM employees
CROSS JOIN departments;
```

## SELF JOIN

A self JOIN is a regular join but the table is joined with itself.

### Syntax

```sql
SELECT a.columns, b.columns
FROM table a, table b
WHERE condition;
```

### Example

```sql
SELECT a.employee_id, a.name, b.name AS manager_name
FROM employees a, employees b
WHERE a.manager_id = b.employee_id;
```

## NATURAL JOIN

A NATURAL JOIN is based on all columns in the two tables that have the same name and selects rows with equal values in the relevant columns.

### Syntax

```sql
SELECT columns
FROM table1
NATURAL JOIN table2;
```

### Example

```sql
SELECT *
FROM employees
NATURAL JOIN departments;
```

## USING Clause

The USING clause is used to specify only those columns that should be used for an EQUIJOIN.

### Syntax

```sql
SELECT columns
FROM table1
JOIN table2
USING (column);
```

### Example

```sql
SELECT employees.name, departments.name
FROM employees
JOIN departments
USING (department_id);
```

<br><br>