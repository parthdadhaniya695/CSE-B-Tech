import { NgFor } from '@angular/common';
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-oned',
  imports: [FormsModule,NgFor],
  templateUrl: './oned.component.html',
  styleUrl: './oned.component.css'
})
export class OnedComponent {
  students = ["parth","rushi","vansh"];

  studentName = '';

  idToEdit = -1;

  insert(){
    if(this.idToEdit<0){
      this.students.push(this.studentName);
    }
    else{
      this.students[this.idToEdit] = this.studentName;
      this.idToEdit = -1;
    }
    
    this.studentName = "";
  }

  deleteStudent(id:any){
    this.students.splice(id,1);
  }

  setForEdit(id:any){
    this.studentName = this.students[id];
    this.idToEdit = id;
  }

}
