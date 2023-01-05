SELECT Roll_no, Name FROM Student;
SELECT Roll_no, Name FROM Student WHERE Batch = “065”;
SELECT * FROM Instructor WHERE Salary>20000
SELECT Code, c.Name, i.Name FROM Course AS c, Instructor AS i WHERE
Instructor_id = i.ID