-- 1.

CREATE VIEW SalePerOrder_(your roll number) AS SELECT orderNumber,

SUM (quantityOrdered * priceEach) total
FROM orderDetails
GROUP by orderNumber
ORDER BY total DESC

-- 2.

SELECT total
FROM salePerOrder_(your roll number)
WHERE orderNumber = 10102

-- 3.
CREATE VIEW vwProducts_(your roll numer) AS
SELECT productCode, productName, buyPrice
FROM products
WHERE buyPrice > (
SELECT AVG (buyPrice) FROM products
)
ORDER BY buyPrice DESC

-- 4.

CREATE VIEW officeInfo_(your roll numer)
AS
SELECT officeCode, phone, city
FROM offices

-- 5.
UPDATE officeInfo
SET phone = 'your phone number'
WHERE officeCode = 4

-- 6.
CREATE VIEW organization_(your roll number)
AS

SELECT CONCAT (E.lastname,E.firstname) AS Employee, CONCAT (M.lastname,M.firstname) AS Manager

FROM employees AS E
INNER JOIN employees AS M
ON M.employeeNumber = E.ReportsTo
ORDER BY Manager

-- 7.
SHOW CREATE VIEW organization_(your roll number)
 
-- 8.

ALTER VIEW organization_(your roll number)
AS

SELECT CONCAT(E.lastname,E.firstname) AS Employee, E.email AS employeeEmail, CONCAT(M.lastname,M.firstname) AS Manager

FROM employees AS E
INNER JOIN employees AS M
ON M.employeeNumber = E.ReportsTo
ORDER BY Manager

-- 9.
DROP VIEW IF EXISTS organization_(your roll number)

-- 10.

CREATE TABLE employees_audit (
id int(11) NOT NULL AUTO_INCREMENT,
employeeNumber int(11) NOT NULL,
lastname varchar(50) NOT NULL,
changedon datetime DEFAULT NULL,
action varchar(50) DEFAULT NULL,
PRIMARY KEY (id)
)


-- 11.
Set the delimiter to | before running the following query

CREATE TRIGGER before_employee_update_(your roll number)
BEFORE UPDATE ON employees
FOR EACH ROW
BEGIN
INSERT INTO employees_audit
SET action = 'update',
employeeNumber = OLD.employeeNumber,
lastname = OLD.lastname,
changedon = NOW();
END|

-- Update a record in the employees table and check the employees_audit table.

-- Why do you think we need to change the delimiter?

-- 12.
SELECT * FROM Information_Schema.Triggers
WHERE Trigger_schema = 'classicmodels' AND
Trigger_name = 'before_employee_update_(your roll number)';

-- 13.
DROP TRIGGER before_employee_update_(your roll number)
