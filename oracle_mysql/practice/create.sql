--------------------- Run first -------------------
@/home/jkalldre/oracle_mysql/practice/clean.sql
@/home/jkalldre/oracle_mysql/practice/customer.sql
@/home/jkalldre/oracle_mysql/practice/orders.sql
---------------------------------------------------

SELECT * FROM customer;

SELECT c.name as "Purchased By", o.item_name, o.date_bought
FROM orders o, customer c
WHERE o.purchased_by=c.id;

COMMIT;
