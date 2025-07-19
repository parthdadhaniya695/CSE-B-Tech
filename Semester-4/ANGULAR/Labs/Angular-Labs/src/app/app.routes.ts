import { Routes } from '@angular/router';
import { ResumeBuilderComponent } from './resume-builder/resume-builder.component';
import { StaticCrudComponent } from './static-crud/static-crud.component';
import { StaticCrudArrayComponent } from './static-crud-array/static-crud-array.component';
import { TempleteDrivenComponent } from './templete-driven/templete-driven.component';
import { ReactiveFormComponent } from './reactive-form/reactive-form.component';

export const routes: Routes = [
    { path : '', component:ResumeBuilderComponent },
    { path : 'resume', component:ResumeBuilderComponent },
    { path : 'static-crud', component:StaticCrudComponent },
    { path : 'array-crud', component:StaticCrudArrayComponent },
    { path : 'templete-driven', component:TempleteDrivenComponent },
    { path : 'reactive-form', component:ReactiveFormComponent },
];
