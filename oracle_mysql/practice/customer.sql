CREATE TABLE customer( id int not null
, name  varchar(15) not null
, age   int         not null
, state varchar(5)
, constraint customer_pk primary key (id));

CREATE SEQUENCE seq1
START WITH 1
INCREMENT BY 1;

INSERT INTO customer
VALUES( seq1.nextval
, 'Jake'
, '23'
, 'TX');

INSERT INTO customer
VALUES( seq1.nextval
, 'Daniel'
, '22'
, 'SC');

INSERT INTO customer
VALUES( seq1.nextval
, 'Colleen'
, '18'
, 'TX');

INSERT INTO customer
VALUES( seq1.nextval
, 'Tara'
, '23'
, 'CA');

