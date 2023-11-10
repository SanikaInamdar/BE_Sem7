
pragma solidity ^0.8.0;

contract StudentData {
    struct Student {
        string name;
        uint age;
        string major;
    }
    
    Student[] public students;
    
    function addStudent(string memory _name, uint _age, string memory _major) public {
        students.push(Student(_name, _age, _major));
    }
    
    function getStudent(uint index) public view returns (string memory, uint, string memory) {
        return (students[index].name, students[index].age, students[index].major);
    }
}
