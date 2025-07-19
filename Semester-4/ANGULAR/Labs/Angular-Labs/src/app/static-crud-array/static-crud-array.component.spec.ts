import { ComponentFixture, TestBed } from '@angular/core/testing';

import { StaticCrudArrayComponent } from './static-crud-array.component';

describe('StaticCrudArrayComponent', () => {
  let component: StaticCrudArrayComponent;
  let fixture: ComponentFixture<StaticCrudArrayComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [StaticCrudArrayComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(StaticCrudArrayComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
