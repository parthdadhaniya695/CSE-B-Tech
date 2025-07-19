import { NgFor } from '@angular/common';
import { Component } from '@angular/core';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-static-crud',
  imports: [FormsModule,NgFor],
  templateUrl: './static-crud.component.html',
  styleUrl: './static-crud.component.css'
})
export class StaticCrudComponent {
  students = ["Michel", "Frankline", "Trevor", "Lester", "Lamar"];

  studentName = "";

  idToEdit = -1;

  insert() {
    if (this.idToEdit < 0) {
      this.students.push(this.studentName);
    }
    else {
      this.students[this.idToEdit] = this.studentName;
      this.idToEdit = -1;
    }

    this.studentName = "";
  }

  deleteStudent(id: any) {
    this.students.splice(id, 1);
  }

  setForEdit(id: any) {
    this.studentName = this.students[id];
    this.idToEdit = id;
  }
}
