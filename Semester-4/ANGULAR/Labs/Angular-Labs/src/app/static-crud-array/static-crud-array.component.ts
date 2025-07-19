import { NgFor } from '@angular/common';
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-static-crud-array',
  imports: [FormsModule,NgFor],
  templateUrl: './static-crud-array.component.html',
  styleUrl: './static-crud-array.component.css'
})
export class StaticCrudArrayComponent {
  students:{FirstName:String,LastName:String,Department:String}[] = [
    {FirstName:"Parth",LastName:"Dadhaniya",Department:"CSE"},
    {FirstName:"Rushi",LastName:"Trivedi",Department:"Mech"},
    {FirstName:"Harsh",LastName:"Shingala",Department:"CSE"},
  ];

  idToEdit = -1;

  tempStudent:{
    FirstName:String,
    LastName:String,
    Department:String
  } = {
    FirstName:'',
    LastName:'',
    Department:''
  };

  saveStudent(){
    if(this.idToEdit<0){
      this.students.push(this.tempStudent);
    }
    else{
      this.students[this.idToEdit] = this.tempStudent;
      this.idToEdit = -1;
    }
    
    this.tempStudent = {
      FirstName:'',
      LastName:'',
      Department:''
    }
  }

  deleteStudent(id:any){
    this.students.splice(id,1);
  }

  setForEdit(id:any){
    this.tempStudent = {...this.students[id]};
    this.idToEdit = id;
  }
}
