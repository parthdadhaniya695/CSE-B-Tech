import { ComponentFixture, TestBed } from '@angular/core/testing';

import { StaticCrudComponent } from './static-crud.component';

describe('StaticCrudComponent', () => {
  let component: StaticCrudComponent;
  let fixture: ComponentFixture<StaticCrudComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [StaticCrudComponent]
    })
    .compileComponents();

    fixture = TestBed.createComponent(StaticCrudComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
